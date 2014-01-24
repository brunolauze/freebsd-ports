# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD: www/webkit-sharp/Makefile 327776 2013-09-20 23:36:50Z bapt $

PORTNAME=	webkit-sharp3
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	www
DISTNAME=	webkit-sharp-${PORTVERSION}
MASTER_SITES=	https://github.com/brunolauze/unixrt/raw/master/distfiles/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for Webkit

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-3.0.pc:${PORTSDIR}/www/webkit-gtk3
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB+=	ASSEMBLY_VERSION=3.0.0

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_AUTOTOOLS=	aclocal libtool autoconf
USE_GNOME=	gnomehack gtksharp30
GNU_CONFIGURE=	yes

CONFIGURE_SCRIPT=autogen.sh

configure: patch do-configure

do-configure:
	@(cd ${WRKSRC} && ./${CONFIGURE_SCRIPT} --prefix=${STAGEDIR}${PREFIX})

NO_STAGE=	yes
.include <bsd.port.mk>
