# Created by: Petri Totterman <petri.totterman@hmv.fi>
# $FreeBSD: devel/log4cplus/Makefile 327724 2013-09-20 17:13:42Z bapt $

PORTNAME=	log4cplus
PORTVERSION=	1.1.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}-rc1.tar.xz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-rc1

MAINTAINER=	reed@reedmedia.net
COMMENT=	A logging library for C++

USE_AUTOTOOLS=	libtool
USE_XZ=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-threads=yes
MAKE_JOBS_UNSAFE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} \
	-e 's|pkgconfigdir = |pkgconfigdir = ${LOCALBASE}/libdata/pkgconfig#|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/include/log4cplus
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/*.config ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/doxygen.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
