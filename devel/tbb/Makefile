# Created by: Arun Sharma <arun@sharma-home.net>
# $FreeBSD: devel/tbb/Makefile 336150 2013-12-11 07:53:16Z martymac $

PORTNAME=	tbb
PORTVERSION=	4.2.2
CATEGORIES=	devel
MASTER_SITES=	http://threadingbuildingblocks.org/sites/default/files/software_releases/source/ \
		LOCAL/martymac
DISTNAME=	${PORTNAME}${PORTVERSION:R:S/.//g}_20131118oss_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A library that provides thread building blocks

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform

USE_LDCONFIG=	yes
USES=	gmake
ALL_TARGET=	default

WRKSRC=	${WRKDIR}/${DISTNAME:S/_src//}

post-extract:
.if ${CC} != "gcc"
	@${CP} ${WRKSRC}/build/FreeBSD.gcc.inc ${WRKSRC}/build/FreeBSD.${CC}.inc
.endif
	@${CP} ${FILESDIR}/version_info_FreeBSD.sh ${WRKSRC}/build/

post-patch:
	@${REINPLACE_CMD} -e 's| -fno-schedule-insns2||g' -e 's|gcc|${CC}|g' -e 's|g++|${CXX}|g' \
		${WRKSRC}/build/FreeBSD.${CC}.inc

do-install:
	cd ${WRKSRC}; \
	${INSTALL_LIB} build/FreeBSD*release/libtbb.so \
		${STAGEDIR}${PREFIX}/lib/libtbb.so.4; \
	${LN} -sf ${PREFIX}/lib/libtbb.so.4 \
		${STAGEDIR}${PREFIX}/lib/libtbb.so; \
	${INSTALL_LIB} build/FreeBSD*release/libtbbmalloc.so \
		${STAGEDIR}${PREFIX}/lib/libtbbmalloc.so.4; \
	${LN} -sf ${PREFIX}/lib/libtbbmalloc.so.4 \
		${STAGEDIR}${PREFIX}/lib/libtbbmalloc.so; \
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tbb/; \
	cd include/tbb/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/tbb/

.include <bsd.port.mk>
