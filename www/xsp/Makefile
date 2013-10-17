# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD: www/xsp/Makefile 327776 2013-09-20 23:36:50Z bapt $

PORTNAME=	xsp
PORTVERSION=    3.0.0
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono based web server

BUILD_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono

MAKE_JOBS_UNSAFE=	yes

USE_SQLITE=	3
CONFIGURE_SCRIPT=autogen.sh
USES=	pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.*" | ${XARGS} ${REINPLACE_CMD} -e 's/pkgconfigdir/pkgconfigdir = \/usr\/local\/libdata\/pkgconfig#/g'

MAN1=		asp-state.1 dbsessmgr.1 mod-mono-server.1 xsp.1 \
		fastcgi-mono-server.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

NO_STAGE=	yes
pre-su-install:
	${MKDIR} ${XSP_DOCROOT}

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
FETCH_CMD=git clone https://github.com/mono/xsp xsp-3.0.0 && tar pczf xsp-3.0.0.tar.gz xsp-3.0.0 && rm -rf xsp-3.0.0 && echo 
