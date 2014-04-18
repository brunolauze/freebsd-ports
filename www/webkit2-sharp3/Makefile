# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD: www/webkit-sharp/Makefile 327776 2013-09-20 23:36:50Z bapt $

PORTNAME=	webkit2-sharp3
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	www
DISTNAME=	webkit2-sharp-${PORTVERSION}
MASTER_SITES=	https://github.com/brunolauze/unixrt/raw/master/distfiles/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for Webkit

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-3.0.pc:${PORTSDIR}/www/webkit-gtk3
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB+=	ASSEMBLY_VERSION=2.2.4

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	gnomehack gtksharp30
GNU_CONFIGURE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e 's/pkgconfigdir/pkgconfigdir = \/usr\/local\/libdata\/pkgconfig#/g'

post-install:
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${DISTNAME}.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig)

NO_STAGE=	yes
.include <bsd.port.mk>
