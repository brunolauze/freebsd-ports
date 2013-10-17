# Created by: Michael Nottebrock <lofi@kiste>
# $FreeBSD: devel/qt5/Makefile 327726 2013-10-14 17:17:44Z blauze $

PORTNAME=	qt5
DISTVERSION=	5.1.1
CATEGORIES=	devel
DIST_SUBDIR=	KDE
MASTER_SITES=	http://download.qt-project.org/official_releases/qt/5.1/5.1.1/single/

DISTNAME=	qt-everywhere-opensource-src-5.1.1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework (metaport)


CONFIGURE_ARGS+= -platform freebsd-g++ \
	-cups \
	-xcb \
	-no-linuxfb \
	-no-eglfs \
	-no-kms \
	-system-zlib \
	-system-sqlite \
	-c++11 \
	-opensource \
	-confirm-license \
	-no-pch \
	-glib \
	-gstreamer \
	-gtkstyle \
	-prefix /usr/local \
	-bindir /usr/local/bin \
	-libdir /usr/local/lib/qt5 \
	-docdir /usr/local/share/doc/qt5 \
	-headerdir /usr/local/include/qt5 \
	-plugindir /usr/local/lib/qt5/plugins \
	-importdir /usr/local/lib/qt5/imports \
	-datadir /usr/local/share/qt5 \
	-translationdir /usr/local/share/qt5/translations \
	-sysconfdir /usr/local/etc/xdg \
	-examplesdir /usr/local/share/examples/qt5/examples \
	-release \
	-no-separate-debug-info \
	-continue \
	-v

do-configure:
	@(cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS})

.include <bsd.port.mk>
