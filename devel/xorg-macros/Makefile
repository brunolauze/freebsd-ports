# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD: trunk/devel/xorg-macros/Makefile 1180 2013-09-30 09:05:02Z zeising $

PORTNAME=	xorg-macros
PORTVERSION=	1.17.1
CATEGORIES=	devel x11
DISTNAME=	util-macros-$(PORTVERSION)

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org development aclocal macros

XORG_CAT=	util

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

PLIST_FILES=	share/aclocal/xorg-macros.m4 \
		libdata/pkgconfig/xorg-macros.pc \
		share/util-macros/INSTALL

PLIST_DIRS=	share/util-macros

.include <bsd.port.mk>
