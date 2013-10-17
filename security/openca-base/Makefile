# Created by: Bruno Lauze <brunolauze@msn.com>
# $FreeBSD$

PORTNAME=      	openca-base
PORTVERSION=  	1.5.1
PORTREVISION= 	1
CATEGORIES=     security   
MASTER_SITES=	SF/openca/${PORTNAME}/releases/v${PORTVERSION}/sources/

MAINTAINER=     brunolauze@msn.com
COMMENT=        OpenCA PKI

BUILD_DEPENDS=	${LOCALBASE}/lib/libssl.so:${PORTSDIR}/security/openssl \
		${LOCALBASE}/bin/openca-sv:${PORTSDIR}/security/openca-tools \
		p5-XML-Parser>=2.41:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Twig>=3.44:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-Locale-libintl>=1.23:${PORTSDIR}/textproc/p5-Locale-libintl \
		p5-File-Temp>=0.23.01:${PORTSDIR}/devel/p5-File-Temp \
		p5-DB_File-Lock>=0.05:${PORTSDIR}/devel/p5-DB_File-Lock \
		p5-Authen-SASL>=2.19:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Digest-HMAC>=1.03:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Digest-MD5>=2.53:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA>=5.85:${PORTSDIR}/security/p5-Digest-SHA \
		p5-Digest-SHA1>=2.13:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-IO-Socket-SSL>=1.953:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Parse-RecDescent>=1.967.009:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-perl-ldap>=0.5700:${PORTSDIR}/net/p5-perl-ldap \
		p5-URI>=1.60:${PORTSDIR}/net/p5-URI \
		p5-Bit-Vector>=7.3:${PORTSDIR}/math/p5-Bit-Vector \
		p5-CGI-Session>=4.48:${PORTSDIR}/www/p5-CGI-Session \
		p5-CGI.pm>=3.69:${PORTSDIR}/www/p5-CGI.pm \
		p5-FCGI>=0.74:${PORTSDIR}/www/p5-FCGI \
		p5-MIME-Lite>=3.02.9:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-MIME-Tools>=5.504:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Mail-Tools>=2.12:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-X500-DN>=0.29:${PORTSDIR}/net/p5-X500-DN \
		p5-Convert-ASN1>=0.26:${PORTSDIR}/converters/p5-Convert-ASN1 \
		p5-MIME-Base64>=3.14:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-XML-SAX-Base>=1.08:${PORTSDIR}/textproc/p5-XML-SAX-Base \
		p5-IO-stringy>=2.110:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Net-Server>=2.007:${PORTSDIR}/net/p5-Net-Server \
		p5-DBI>=1.628:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-Pg>=2.19.3:${PORTSDIR}/databases/p5-DBD-Pg


GNU_CONFIGURE=	yes
USES=         	gmake pkgconfig


CONFIGURE_ARGS+=	--enable-scep \
			--localstatedir=/var \
			--with-var-prefix=/var \
			--with-service-mail-account=service@unixrt.org \
			--with-support-mail-address=support@unixrt.org \
			--with-httpd-fs-prefix=${PREFIX}/www/openca \
			--with-sendmail=/usr/sbin/sendmail \
			--with-db-passwd=P0l3n0rd


PREFIX=		${WRKDIR}/stage
NO_STAGE=	yes

.include <bsd.port.mk>
