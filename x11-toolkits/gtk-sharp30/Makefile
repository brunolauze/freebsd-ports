# Created by: Juli Mallett
# $FreeBSD: x11-toolkits/gtk-sharp30/Makefile 327785 2013-09-20 23:57:47Z bapt $

PORTNAME=       gtk-sharp3
PORTVERSION=    2.99.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML

LATEST_LINK=	gtk-sharp30

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		perl5 gmake pkgconfig
USE_PERL5=	run
#USE_GNOME=	gnomehack gtk20 libglade2

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" | ${XARGS} ${REINPLACE_CMD} -e 's/pkgconfigdir/pkgconfigdir = \/usr\/local\/libdata\/pkgconfig#/g'
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
CONFIGURE_SCRIPT=autogen.sh
CONFIGURE_ARGS+=  --program-prefix= --enable-program-transform-name=
FETCH_CMD=git clone https://github.com/mono/gtk-sharp gtk-sharp3-2.99.2 && tar pczf gtk-sharp3-2.99.2.tar.gz gtk-sharp3-2.99.2 && rm -rf gtk-sharp3-2.99.2 && echo 
