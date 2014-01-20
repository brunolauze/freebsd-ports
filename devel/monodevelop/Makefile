# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD: devel/monodevelop/Makefile 327724 2013-09-20 17:13:42Z bapt $

PORTNAME=	monodevelop
PORTVERSION=	4.2.3
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	IDE for the .NET platform

BUILD_DEPENDS=	mautil:${PORTSDIR}/devel/mono-addins
RUN_DEPENDS=	${LOCALBASE}/lib/libgdiplus.a:${PORTSDIR}/x11-toolkits/libgdiplus \
		exctags:${PORTSDIR}/devel/ctags \
		git:${PORTSDIR}/devel/git \
		mautil:${PORTSDIR}/devel/mono-addins

LIB_PC_DEPENDS= ${LOCALBASE}/libdata/pkgconfig/mono.pc:${PORTSDIR}/lang/mono \
                ${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:${PORTSDIR}/devel/dbus-sharp-glib \
                ${LOCALBASE}/libdata/pkgconfig/taglib-sharp.pc:${PORTSDIR}/audio/taglib-sharp \
                ${LOCALBASE}/libdata/pkgconfig/mono-zeroconf.pc:${PORTSDIR}/net/mono-zeroconf \
                ${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins \
                ${LOCALBASE}/libdata/pkgconfig/notify-sharp.pc:${PORTSDIR}/devel/notify-sharp \
		${LOCALBASE}/libdata/pkgconfig/gdata-sharp-youtube.pc:${PORTSDIR}/devel/google-gdata \
		${LOCALBASE}/libdata/pkgconfig/gtk-sharp-beans-2.0.pc:${PORTSDIR}/x11-toolkits/gtk-sharp-beans

USE_GNOME=	gnomehack gtksharp20 gnomesharp20
USE_AUTOTOOLS=	autoconf autoheader automake libtool
MAN1=		mdtool.1 monodevelop.1
USES=		desktop-file-utils gettext gmake pkgconfig
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	MONOEXT GIT SVN
OPTIONS_DEFAULT=	MONOEXT GIT SVN
MONOEXT_DESC=	Extensions for Mono development
GIT_DESC=	git support

MONOEXT_CONFIGURE_ENABLE=	monoextensions
GIT_CONFIGURE_ENABLE=		git
GIT_RUN_DEPENDS=	git:${PORTSDIR}/devel/git
SVN_CONFIGURE_ENABLE=		subversion
SVN_RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even


FETCH_CMD=      git clone https://github.com/mono/monodevelop ${PORTNAME}-${PORTVERSION} && cd ${PORTNAME}-${PORTVERSION} && git submodule update --init --recursive && cd .. && tar pczf ${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-${PORTVERSION} && rm -rf ${PORTNAME}-${PORTVERSION} && echo 

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|[(]gnome_data[)]/mime$$|(prefix)/share/mime|g ; \
		s|[(]gnome_data[)]/mime/packages$$|(prefix)/share/mime/packages|g ; \
		s|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/main/Makefile.am
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/main/monodevelop.in \
		${WRKSRC}/main/mdtool.in


CONFIGURE_SCRIPT=autogen.sh

do-configure:
	@(cd ${WRKSRC} && ./${CONFIGURE_SCRIPT} --prefix=${STAGEDIR}${PREFIX} --profile=dist)

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
