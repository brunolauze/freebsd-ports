# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/webkit-gtk3/Makefile 18629 2013-07-19 20:42:52Z kwm $

PORTNAME=	webkit
PORTVERSION=	2.2.4
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	-gtk2
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit
NO_STAGE=	yes
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		gtkdoc-rebase:${PORTSDIR}/textproc/gtk-doc \
		mutter:${PORTSDIR}/x11-wm/mutter
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libicutu.so:${PORTSDIR}/devel/icu \
		libharfbuzz.so:${PORTSDIR}/print/harfbuzz \
		libwebp.so:${PORTSDIR}/graphics/webp \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libEGL.so:${PORTSDIR}/graphics/libEGL

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

USE_XZ=		yes
USE_GSTREAMER1=	yes
USE_XORG=	xt xdamage xcomposite
USES=		bison gettext gmake perl5 pkgconfig shebangfix
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GNOME=	cairo gnomehier gtk20 introspection:build \
		libxslt:build
USE_SQLITE=	3
USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_FLEX="${LOCALBASE}/bin/flex" \
		ZLIB_CFLAGS="-I/usr/include" \
		ZLIB_LIBS="-L/usr/lib -lz" \
		ac_cv_path_DOLT_BASH=""
CPPFLAGS+=	-I${LOCALBASE}/include -I/usr/include/c++/v1
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--enable-svg-fonts \
		--disable-geolocation \
		--enable-introspection \
		--enable-developer-mode \
		--enable-accelerated-compositing \
		--with-wayland-target=no
MAKEFILE=	GNUmakefile

#CONFIGURE_ARGS+=--disable-silent-rules
CONFIGURE_ARGS+=--enable-egl \
		--disable-gles2
#		--with-acceleration-backend=opengl # clutter broken?
# opengl, clutter, none (clutter unsupported)

SHEBANG_FILES=	\
	Source/JavaScriptCore/create_hash_table \
	Source/WebCore/css/*.pl \
	Source/WebCore/dom/*.pl \
	Source/WebCore/make-hash-tools.pl \
	Source/WebCore/page/make_settings.pl \
	Source/WebCore/platform/text/mac/make-charset-table.pl \
	Source/WebCore/bindings/scripts/*.p[lm] \
	Source/JavaScriptCore/create_hash_table

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk2
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_DEFINE=	WEBGL WEBAUDIO DEBUG FULLDEBUG
OPTIONS_DEFAULT=WEBGL WEBAUDIO
WEBAUDIO_DESC=	Web audio support
WEBGL_DESC=	Enable Web GL support
DEBUG_DESC=	Just enable debug symbols
FULLDEBUG_DESC=	Enable asserts and other debug support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBGL}
USE_GL=		gl
CONFIGURE_ARGS+=--enable-webgl
.else
CONFIGURE_ARGS+=--disable-webgl
.endif

.if ${PORT_OPTIONS:MWEBAUDIO}
CONFIGURE_ARGS+=--enable-web-audio
.else
CONFIGURE_ARGS+=--disable-web-audio
.endif

.if ${PORT_OPTIONS:MFULLDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug-symbols=yes
.endif

# gtest to use <tr1/tuple,> while libc++ only has <tuple>
CPPFLAGS+=	-DGTEST_USE_OWN_TR1_TUPLE
# Shutup warning spam
CXXFLAGS+=	-Wno-c++11-extensions -Qunused-arguments

CONFIGURE_ARGS+=--disable-webkit2

# We need clang + libc++ or gcc 4.7+. gcc has libstdc++ conflict between
# gcc port and base. This originates from icu
CXXFLAGS+=	-stdlib=libc++
LDFLAGS+=	-stdlib=libc++
. if ${OSVERSION}<1000019
BUILD_DEPENDS+=	clang>=3.3_1:${PORTSDIR}/lang/clang33 \
		libc++>=0:${PORTSDIR}/devel/libc++
RUN_DEPENDS+=	libc++>=0:${PORTSDIR}/devel/libc++
CC=		clang33
CXX=		clang++33
CPP=		clang-cpp33
CONFIGURE_ENV+=	CC=${CC} CXX=${CXX} CPP=${CPP}
. endif

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
BUILD_DEPENDS+=	p5-Switch>0:${PORTSDIR}/lang/p5-Switch
.endif

post-patch:
	@${CHMOD} +x ${WRKSRC}/create_webcorelayer.sh
	@${ECHO} "1.0" > ${WRKSRC}/Documentation/webkitgtk/version.xml
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebCore/plugins/PluginDatabase.cpp
	@${FIND} ${WRKSRC} -name GNUmakefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|' \
		${WRKSRC}/Source/WebCore/dom/make_names.pl \
		${WRKSRC}/Source/WebCore/css/make-css-file-arrays.pl \
		${WRKSRC}/Source/WebCore/bindings/scripts/IDLParser.pm
	@${REINPLACE_CMD} -e 's|"gperf|"${LOCALBASE}/bin/gperf|g' \
		${WRKSRC}/Source/WebCore/css/makevalues.pl \
		${WRKSRC}/Source/WebCore/css/makeprop.pl \
		${WRKSRC}/Source/WebCore/make-hash-tools.pl

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Programs/GtkLauncher \
		${STAGEDIR}${PREFIX}/bin/GtkLauncher-1

.include <bsd.port.post.mk>
