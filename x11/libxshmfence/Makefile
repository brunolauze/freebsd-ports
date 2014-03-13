# $FreeBSD: jkim/devel/libxshmfence/Makefile 20430 2013-12-09 22:08:09Z jkim $

PORTNAME=	libxshmfence
PORTVERSION=	1.1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Shared memory 'SyncFence' synchronization primitive

LICENSE=	MIT

XORG_CAT=	lib

USE_XORG=	xproto

CONFIGURE_ARGS+=        --with-shared-memory-dir=/tmp

.include <bsd.port.mk>
