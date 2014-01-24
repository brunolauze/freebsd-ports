# $FreeBSD: devel/mono-addins/Makefile 327724 2013-09-20 17:13:42Z bapt $

PORTNAME=	mono-addins
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono framework to create extensible applications

LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono.pc:${PORTSDIR}/lang/mono

BUILD_DEPENDS+=	${LIB_PC_DEPENDS}
RUN_DEPENDS+=	${LIB_PC_DEPENDS}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
WANT_GNOME=	yes
MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=yes
GH_ACCOUNT=	mono
GH_PROJECT=	mono-addins
GH_TAGNAME=	64a45d9
GH_COMMIT=	${GH_TAGNAME}


OPTIONS_DEFINE=	GTK2
OPTIONS_DEFAULT=	GTK2

MAN1=		mautil.1

PLIST_SUB+=	VER=1.0.0

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtksharp20
CONFIGURE_ARGS+=	--enable-gui
PLIST_SUB+=	OPT_GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	OPT_GTK2="@comment "
.endif

.include <bsd.port.post.mk>
