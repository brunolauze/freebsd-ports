# Created by: Juli Mallett
# $FreeBSD: x11-toolkits/gtk-sharp20/Makefile 334017 2013-11-16 17:58:27Z romain $

PORTNAME=	gtk-sharp
PORTVERSION=	2.12.10
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	20

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GTK+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		automake:${PORTSDIR}/devel/automake
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML

CONFIGURE_SCRIPT=bootstrap-2.12
FETCH_CMD=	git clone -b ${PORTNAME}-2-12-branch https://github.com/mono/${PORTNAME} ${PORTNAME}-${PORTVERSION} && tar pczf ${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-${PORTVERSION} && rm -rf ${PORTNAME}-${PORTVERSION} && echo

LATEST_LINK=	gtk-sharp20
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	gtk20 libglade2
USES=		gmake pathfix perl5 pkgconfig
USE_PERL5=	run
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}

post-patch:
	@${FIND} ${WRKSRC} -name '*.pl' | ${XARGS} ${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|'
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/glib/glue/*.c
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} \
	-e 's|pkgconfigdir = |pkgconfigdir = ${LOCALBASE}/libdata/pkgconfig#|g'

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
