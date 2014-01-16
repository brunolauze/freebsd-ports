# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD: lang/mono/Makefile 327741 2013-09-20 19:53:09Z bapt $

PORTNAME=	mono
PORTVERSION=	3.2.7
CATEGORIES=	lang
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	An open source implementation of .NET Development Framework

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
    		bash:${PORTSDIR}/shells/bash \
    		wget:${PORTSDIR}/ftp/wget \
		curl:${PORTSDIR}/ftp/curl \
		git:${PORTSDIR}/devel/git \
		llvm-config:${PORTSDIR}/devel/llvm-mono

USES=		bison gettext gmake pathfix perl5
USE_AUTOTOOLS=	aclocal libtool
USE_GNOME=	glib20
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes


MONOLITE_DISTFILE=monolite-111-latest.tar.gz

FETCH_CMD=	fetch http://storage.bos.xamarin.com/mono-dist-master/latest/${MONOLITE_DISTFILE} && git clone https://github.com/mono/mono ${PORTNAME}-${PORTVERSION} && tar pczf ${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-${PORTVERSION} && rm -rf ${PORTNAME}-${PORTVERSION} && echo

# Moonlight is installed as part of www/moonlight
CONFIGURE_ARGS+= --with-moonlight=no --disable-dtrace --with-tls=__thread --with-sgen=yes 
CONFIGURE_ARGS+= --enable-llvm --enable-loadedllvm --enable-parallel-mark --enable-native-types --enable-gsharing

CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=no

# Set location for .wapi creation.
MONO_SHARED_DIR=${WRKDIR}

# LC_ALL is set in order to work around issues people are having when using
# other languages.  This has shown itself in build fails and possibly other
# strange crashes.
MAKE_ENV=	MONO_SHARED_DIR="${MONO_SHARED_DIR}" \
		LC_ALL=C EXTERNAL_MCS="./mcs/class/lib/monolite/gmcs.exe"

ONLY_FOR_ARCHS=	i386 amd64 powerpc

MAN1=		al.1 cccheck.1 ccrewrite.1 cert2spc.1 certmgr.1 chktrust.1 \
		cilc.1 crlupdate.1 csharp.1 disco.1 dtd2xsd.1 gacutil.1 \
		genxs.1 httpcfg.1 ilasm.1 lc.1 macpack.1 makecert.1 mconfig.1 \
		mcs.1 mdassembler.1 mdoc-assemble.1 mdoc-export-html.1 \
		mdoc-export-msxdoc.1 mdoc-update.1 mdoc-validate.1 mdoc.1 \
		mdvalidater.1 mkbundle.1 mono-api-info.1 mono-cil-strip.1 \
		mono-configuration-crypto.1 mono-service.1 mono-shlib-cop.1 \
		mono-xmltool.1 mono.1 monodis.1 monodocer.1 monodocs2html.1 \
		monolinker.1 monop.1 mozroots.1 mprof-report.1 pdb2mdb.1 \
		permview.1 prj2make.1 resgen.1 secutil.1 setreg.1 sgen.1 \
		signcode.1 sn.1 soapsuds.1 sqlsharp.1 wsdl.1 xbuild.1 xsd.1
MAN5=		mdoc.5 mono-config.5

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-everything::
	@${CAT} ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/mcs/class/Managed.Windows.Forms/build-csproj \
		${WRKSRC}/mcs/class/Managed.Windows.Forms/build-csproj2k5 \
		${WRKSRC}/mcs/class/Mono.WebBrowser/build-csproj2k5
	@${FIND} ${WRKSRC} -name '*.sh' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^#!/bin/bash|#!/bin/sh|g'
	@${REINPLACE_CMD} 's/(1)/(1.0)/g' ${WRKSRC}/configure.in

tests: build
	@${ECHO_MSG} "===> Running mono regression tests"
	@(cd ${WRKSRC}/mono/tests && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} test)

CONFIGURE_SCRIPT=autogen.sh

post-configure:
	@${REINPLACE_CMD} -e 's|share\/man|man|g' \
		${WRKSRC}/mcs/jay/Makefile
	@(cd ${WRKSRC} && ${GMAKE} monolite_url=file://${PORTSDIR}/distfiles/${MONOLITE_DISTFILE} get-monolite-latest)

.include "${PORTSDIR}/lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
