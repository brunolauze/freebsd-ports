
PORTNAME=	bindinator
PORTVERSION=	1.0
CATEGORIES=	devel
MAINTAINER=     mono@FreeBSD.org
COMMENT=        Binding Generator for gobject introspection based librairies for the .NET platform


USE_GITHUB=	yes
GH_ACCOUNT=	mono-soc-2013
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	6cd15be
GH_COMMIT=	${GH_TAGNAME}

GNU_CONFIGURE=	yes


USES=	gmake perl5
USE_AUTOTOOL= libtool
CONFIGURE_SCRIPT=autogen.sh

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono

.include <bsd.port.mk>
