# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47-webkit
PORTVERSION=	4.7.2
RPMVERSION=	1_18.el5
USE_LINUX=	c6
USE_LINUX_APPS=	fontconfig png xorglibs sqlite3 qt47 qt47-x11

CATEGORIES=	www linux
MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS 5)

MASTER_SITES=	http://dl.atrpms.net/el5-i386/atrpms/testing/
PKGNAMEPREFIX=	linux-${USE_LINUX}-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}
DIST_SUBDIR=	rpm/${LINUX_RPM_ARCH}/centos/c5

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	5
USE_LDCONFIG=	yes

SRC_SUFX=	.i386.rpm

.include <bsd.port.mk>
