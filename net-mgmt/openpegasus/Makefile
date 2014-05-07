

PORTNAME=	openpegasus
PORTVERSION=	2.14.0
CATEGORIES=	net-mgmt

MAINTAINER=	brunolauze@msn.com
COMMENT=	OpenPegasus Web Management Instrumentation

USES=		gettext gmake pkgconfig perl5
GNU_CONFIGURE=	yes

FETCH_DEPENDS=	cvs:${PORTSDIR}/devel/cvs

LIB_DEPENDS=	libslp.so:${PORTSDIR}/net/openslp \
		libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

FETCH_CMD= sh -c "export CVSROOT=:pserver:anon:anon@cvs.opengroup.org:/cvs/MSB && export CVS_PASS=anon && cvs login && cvs co pegasus && find ./pegasus -name 'CVS' -exec rm -rf {} + && mv pegasus ${PORTNAME}-${PORTVERSION} && tar pczf ${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-${PORTVERSION} && rm -rf ${PORTNAME}-${PORTVERSION}" && echo 

MAKEFILE=Makefile.Release
ALL_TARGET=rebuild

USERS=  cimsrvr
GROUPS= cimsrvr

PEGASUS_ROOT=${WRKSRC}
PEGASUS_HOME=${PEGASUS_ROOT}/out/Debug
PEGASUS_PLATFORM=FREEBSD_X86_64_CLANG

PEGASUS_PREFIX=${PREFIX}

# OpenPegasus SSL support
OPENSSL_HOME=/usr
PEGASUS_HAS_SSL=yes
PEGASUS_ENABLE_SSLV2=yes
PEGASUS_TRACE_FILE_PATH=/var/log/cimserver.log
PEGASUS_LOG_DIR=/var/log/pegasus

PEGASUS_CONFIG_DIR="${PREFIX}/etc/pegasus"
PEGASUS_SSL_CERT_FILE_PATH="${PREFIX}/etc/pegasus/server.pem"
PEGASUS_SSL_KEY_FILE_PATH="${PREFIX}/etc/pegasus/file.pem"
PEGASUS_SSL_SERVER_TRUSTSTORE="${PREFIX}/etc/pegasus"
PEGASUS_CRL_VERIFICATION="${PREFIX}/etc/pegasus"
PEGASUS_SSL_SERVER_CRL="${PREFIX}/etc/pegasus"
PEGASUS_REPOSITORY_DIR="${PREFIX}/share/pegasus/repository"
PEGASUS_CIM_SCHEMA=CIM240
ALLOW_EXPERIMENTAL="-aEV"

# OpenPegasus SLP support
PEGASUS_OPENSLP_HOME=${LOCALBASE}
PEGASUS_ENABLE_SLP=true
PEGASUS_USE_EXTERNAL_SLP=openslp

# OpenPegasus User authentication & authorization
PEGASUS_ENABLE_USERGROUP_AUTHORIZATION=true
PEGASUS_PAM_AUTHENTICATION=true

# OpenPegasus ExecQuery() method support
PEGASUS_ENABLE_EXECQUERY=true

PEGASUS_ENABLE_CMPI_PROVIDER_MANAGER=true
PEGASUS_SUPPORTS_DYNLIB="yes"
PEGASUS_USE_EXPERIMENTAL_INTERFACES=true
PEGASUS_DISABLE_DEPRECATED_INTERFACES=false
PEGASUS_REPOSITORY_MODE=BIN
PEGASUS_ADVANCED_CIMCLIENT=true
PEGASUS_ENABLE_PROTOCOL_BINARY=true
PEGASUS_ENABLE_PROTOCOL_WSMAN=true
PEGASUS_DEFAULT_ENABLE_OOP=true
PEGASUS_ENABLE_DMTF_INDICATION_PROFILE_SUPPORT=true
PEGASUS_ENABLE_EMAIL_HANDLER=true
PEGASUS_ENABLE_SYSTEM_LOG_HANDLER=true
PEGASUS_NET_SNMP_INCLUDE_DIR=/usr/local/include
PEGASUS_NET_SNMP_LIB_DIR=/usr/local/lib

PEGASUS_ENVVAR_FILE=${WRKSRC}/env_var_FreeBSD.status

CFLAGS+=        -DPEGASUS_PAM_AUTHENTICATION=1 -DPEGASUS_ENABLE_USERGROUP_AUTHORIZATION=1 \
                -DPEGASUS_ENABLE_EXECQUERY=1 -DPEGASUS_ENABLE_SLP -DPEGASUS_HAS_SSL=1 \
                -DPEGASUS_USE_EXTERNAL_SLP=1 

CXXFLAGS+=      -DOPENSSL_HOME=${OPENSSL_HOME} -DPEGASUS_HAS_SSL=1 -DPEGASUS_ENABLE_SSLV2=1 \
                -DPEGASUS_OPENSLP_HOME=\"${PEGASUS_OPENSLP_HOME}\" \
                -DPEGASUS_ENABLE_SLP=1 \
		-DPEGASUS_USE_EXTERNAL_SLP=1 \
                -DPEGASUS_ENABLE_USERGROUP_AUTHORIZATION=1 \
                -DPEGASUS_PAM_AUTHENTICATION=1 \
                -DPEGASUS_ENABLE_EXECQUERY=1 \
                -DPEGASUS_ENABLE_CMPI_PROVIDER_MANAGER=1 \
                -DPEGASUS_SUPPORTS_DYNLIB=1 \
                -DPEGASUS_USE_EXPERIMENTAL_INTERFACES=1 \
                -DPEGASUS_DISABLE_DEPRECATED_INTERFACES=1 \
                -DPEGASUS_REPOSITORY_MODE=BIN \
                -DPEGASUS_ADVANCED_CIMCLIENT=1 \
                -DPEGASUS_ENABLE_PROTOCOL_BINARY=1 \
		-DPEGASUS_ENABLE_PROTOCOL_WSMAN \
		-DPEGASUS_CONFIG_DIR=\"${PEGASUS_CONFIG_DIR}\" \
		-DPEGASUS_SSL_CERT_FILE_PATH=\"${PEGASUS_SSL_CERT_FILE_PATH}\" \
		-DPEGASUS_SSL_KEY_FILE_PATH=\"${PEGASUS_SSL_KEY_FILE_PATH}\" \
		-DPEGASUS_SSL_SERVER_TRUSTSTORE=\"${PEGASUS_SSL_SERVER_TRUSTSTORE}\" \
		-DPEGASUS_CRL_VERIFICATION=\"${PEGASUS_CRL_VERIFICATION}\" \
		-DPEGASUS_SSL_SERVER_CRL=\"${PEGASUS_SSL_SERVER_CRL}\" \
		-DPEGASUS_REPOSITORY_DIR=\"${PEGASUS_REPOSITORY_DIR}\" \
		-DPEGASUS_CIM_SCHEMA=CIM240


CONFIGURE_ENV+= PEGASUS_ROOT=${PEGASUS_ROOT} PEGASUS_HOME=${PEGASUS_HOME} \
                PEGASUS_PLATFORM=${PEGASUS_PLATFORM} OPENSSL_HOME=${OPENSSL_HOME} \
                PEGASUS_HAS_SSL=${PEGASUS_HAS_SSL} \
		PEGASUS_ENABLE_SSLV2=${PEGASUS_ENABLE_SSLV2} \
                PEGASUS_OPENSLP_HOME=${PEGASUS_OPENSLP_HOME} \
                PEGASUS_ENABLE_SLP=${PEGASUS_ENABLE_SLP} \
                PEGASUS_ENABLE_USERGROUP_AUTHORIZATION=${PEGASUS_ENABLE_USERGROUP_AUTHORIZATION} \
                PEGASUS_PAM_AUTHENTICATION=${PEGASUS_PAM_AUTHENTICATION} \
                PEGASUS_ENABLE_EXECQUERY=${PEGASUS_ENABLE_EXECQUERY} \
		PEGASUS_ENABLE_PROTOCOL_WSMAN=${PEGASUS_ENABLE_PROTOCOL_WSMAN} \
		PEGASUS_CIM_SCHEMA=${PEGASUS_CIM_SCHEMA} \
		ALLOW_EXPERIMENTAL=${ALLOW_EXPERIMENTAL} \
		PEGASUS_DEFAULT_ENABLE_OOP=${PEGASUS_DEFAULT_ENABLE_OOP} \
		PEGASUS_ENABLE_DMTF_INDICATION_PROFILE_SUPPORT=${PEGASUS_ENABLE_DMTF_INDICATION_PROFILE_SUPPORT} \
		PEGASUS_ENABLE_EMAIL_HANDLER=${PEGASUS_ENABLE_EMAIL_HANDLER} \
		PEGASUS_ENABLE_SYSTEM_LOG_HANDLER=${PEGASUS_ENABLE_SYSTEM_LOG_HANDLER} \
		PEGASUS_NET_SNMP_INCLUDE_DIR=${PEGASUS_NET_SNMP_INCLUDE_DIR} \
		PEGASUS_NET_SNMP_LIB_DIR=${PEGASUS_NET_SNMP_LIB_DIR} \
		PEGASUS_ENVVAR_FILE=${PEGASUS_ENVVAR_FILE}

MAKE_ENV+=      PEGASUS_ROOT=${PEGASUS_ROOT} PEGASUS_HOME=${PEGASUS_HOME} \
                PEGASUS_PLATFORM=${PEGASUS_PLATFORM} OPENSSL_HOME=${OPENSSL_HOME} \
                PEGASUS_HAS_SSL=${PEGASUS_HAS_SSL} \
		PEGASUS_ENABLE_SSLV2=${PEGASUS_ENABLE_SSLV2} \
		PEGASUS_OPENSLP_HOME=${PEGASUS_OPENSLP_HOME} \
                PEGASUS_ENABLE_SLP=${PEGASUS_ENABLE_SLP} \
                PEGASUS_ENABLE_USERGROUP_AUTHORIZATION=${PEGASUS_ENABLE_USERGROUP_AUTHORIZATION} \
                PEGASUS_PAM_AUTHENTICATION=${PEGASUS_PAM_AUTHENTICATION} \
                PEGASUS_ENABLE_EXECQUERY=${PEGASUS_ENABLE_EXECQUERY} \
                PEGASUS_ENABLE_CMPI_PROVIDER_MANAGER=${PEGASUS_ENABLE_CMPI_PROVIDER_MANAGER} \
                PEGASUS_SUPPORTS_DYNLIB=${PEGASUS_SUPPORTS_DYNLIB} \
                PEGASUS_USE_EXPERIMENTAL_INTERFACES=${PEGASUS_USE_EXPERIMENTAL_INTERFACES} \
                PEGASUS_DISABLE_DEPRECATED_INTERFACES=${PEGASUS_DISABLE_DEPRECATED_INTERFACES} \
                PEGASUS_REPOSITORY_MODE=${PEGASUS_REPOSITORY_MODE} \
                PEGASUS_ADVANCED_CIMCLIENT=${PEGASUS_ADVANCED_CIMCLIENT} \
                PEGASUS_ENABLE_PROTOCOL_BINARY=${PEGASUS_ENABLE_PROTOCOL_BINARY} \
		PEGASUS_ENABLE_PROTOCOL_WSMAN=${PEGASUS_ENABLE_PROTOCOL_WSMAN} \
		PEGASUS_CONFIG_DIR=${PEGASUS_CONFIG_DIR} \
		PEGASUS_SSL_CERT_FILE_PATH=${PEGASUS_SSL_CERT_FILE_PATH} \
		PEGASUS_SSL_KEY_FILE_PATH=${PEGASUS_SSL_KEY_FILE_PATH} \
		PEGASUS_SSL_SERVER_TRUSTSTORE=${PEGASUS_SSL_SERVER_TRUSTSTORE} \
		PEGASUS_CRL_VERIFICATION=${PEGASUS_CRL_VERIFICATION} \
		PEGASUS_SSL_SERVER_CRL=${PEGASUS_SSL_SERVER_CRL} \
		PEGASUS_REPOSITORY_DIR=${PEGASUS_REPOSITORY_DIR} \
		PEGASUS_CIM_SCHEMA=${PEGASUS_CIM_SCHEMA} \
		ALLOW_EXPERIMENTAL=${ALLOW_EXPERIMENTAL} \
		PEGASUS_DEFAULT_ENABLE_OOP=${PEGASUS_DEFAULT_ENABLE_OOP} \
		PEGASUS_ENABLE_DMTF_INDICATION_PROFILE_SUPPORT=${PEGASUS_ENABLE_DMTF_INDICATION_PROFILE_SUPPORT} \
		PEGASUS_ENABLE_EMAIL_HANDLER=${PEGASUS_ENABLE_EMAIL_HANDLER} \
		PEGASUS_ENABLE_SYSTEM_LOG_HANDLER=${PEGASUS_ENABLE_SYSTEM_LOG_HANDLER} \
		PEGASUS_NET_SNMP_INCLUDE_DIR=${PEGASUS_NET_SNMP_INCLUDE_DIR} \
		PEGASUS_NET_SNMP_LIB_DIR=${PEGASUS_NET_SNMP_LIB_DIR} \
		PEGASUS_ENVVAR_FILE=${PEGASUS_ENVVAR_FILE} \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" DEFINES="${CXXFLAGS}" \
                LD_LIBRARY_PATH=${PEGASUS_HOME}/lib: \
                PATH=${PEGASUS_HOME}/bin:${LOCALBASE}/bin:${LOCALBASE}/sbin:/sbin:/usr/bin:/bin

SUB_FILES=	SampleCMPIInstanceClient \
		chksrc \
		cimauth \
		cimcli \
		cimconfig \
		cimcrl \
		cimlistener \
		cimmof \
		cimmofl \
		cimperf \
		cimprovagt \
		cimprovider \
		cimreparchive \
		cimserver \
		cimserverd \
		cimsub \
		cimtrust \
		ipinfo \
		loadxml \
		osinfo \
		repupgrade \
		tomof \
		wbemexec \
		cimserver_planned.conf \
		wbem \

SUB_LIST+=	COMMENT="${COMMENT}" \
		PEGASUS_PREFIX=${PEGASUS_PREFIX}

.include <bsd.port.pre.mk>

configure: do-configure

do-configure: patch
	@(echo "Configuration done...")
	touch ${WRKDIR}/.configure_done.openpegasus._usr_local

REPOSITORY_TYPE=Experimental

post-patch:
	fetch http://dmtf.org/sites/default/files/cim/cim_schema_v2400/cim_schema_2.40.0${REPOSITORY_TYPE}-MOFs.zip
	PEGASUS_ROOT=${WRKSRC} ${WRKSRC}/mak/CreateDmtfSchema 240 ${PWD}/cim_schema_2.40.0${REPOSITORY_TYPE}-MOFs.zip cim_schema_2.40.0
	rm cim_schema_2.40.0${REPOSITORY_TYPE}-MOFs.zip
	cd ${WRKSRC} && patch -b.orig < ${FILESDIR}/extra-CIM240-qualifiers
	cd ${WRKSRC} && patch -b.orig < ${FILESDIR}/extra-CIM240-${REPOSITORY_TYPE}-CIM_Core.mof
	cd ${WRKSRC} && patch -b.orig < ${FILESDIR}/extra-CIM240-${REPOSITORY_TYPE}-CIM_Interop.mof
.if ${REPOSITORY_TYPE} == "Experimental"
	cd ${WRKSRC} && patch -b.orig < ${FILESDIR}/extra-CIM240-${REPOSITORY_TYPE}-CIM_Event.mof
	cd ${WRKSRC} && patch -b.orig < ${FILESDIR}/extra-CIM240-${REPOSITORY_TYPE}-DMTF__Core__CIM_AllocatedLogicalElement.mof
	cd ${WRKSRC} && patch -b.orig < ${FILESDIR}/extra-CIM240-${REPOSITORY_TYPE}-DMTF__Core__CIM_LogicalDevice.mof
	cd ${WRKSRC} && patch -b.orig < ${FILESDIR}/extra-CIM240-${REPOSITORY_TYPE}-DMTF__Network__CIM_IPSubinterface.mof
.endif

post-build: repository

repository:
	@(cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} repository)
	@(cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} setupdevserver)


COPYTREE_HEADER=/bin/sh -c '(/usr/bin/find -d $$0 -name "*.h"  -not -path "*/tests/*" | /usr/bin/cpio -dumpl $$1 >/dev/null  2>&1) &&  /usr/sbin/chown -Rh root:wheel $$1 && /usr/bin/find -d $$0 -name "*.h"  -not -path "*/tests/*" -type d -exec chmod 755 $$1/{} \; &&  /usr/bin/find -d $$0 -name "*.h"  -not -path "*/tests/*" -type f -exec chmod 444 $$1/{} \;' --

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Client
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Common
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Config
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Consumer
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/General
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Provider
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Query
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Query/QueryCommon
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Query/QueryExpression
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/CQL
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/FQL
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/WQL
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/lib/providers
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pegasus
	${MKDIR} ${STAGEDIR}${PREFIX}/www
	${MKDIR} ${STAGEDIR}${PREFIX}/www/pegasus
	cd ${PEGASUS_HOME}/stagingDir/${PREFIX}/lib && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/lib/
	cd ${PEGASUS_HOME}/stagingDir/${PREFIX}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/
	${INSTALL_PROGRAM} ${PEGASUS_HOME}/bin/cimcli ${STAGEDIR}${PREFIX}/lib/pegasus/bin/cimcli
	${INSTALL_PROGRAM} ${PEGASUS_HOME}/bin/cimcrl ${STAGEDIR}${PREFIX}/lib/pegasus/bin/cimcrl
	${INSTALL_PROGRAM} ${PEGASUS_HOME}/bin/cimlistener ${STAGEDIR}${PREFIX}/lib/pegasus/bin/cimlistener
	${INSTALL_PROGRAM} ${PEGASUS_HOME}/bin/cimperf ${STAGEDIR}${PREFIX}/lib/pegasus/bin/cimperf
	${INSTALL_PROGRAM} ${PEGASUS_HOME}/bin/tomof ${STAGEDIR}${PREFIX}/lib/pegasus/bin/tomof
	${INSTALL_PROGRAM} ${PEGASUS_HOME}/bin/loadxml ${STAGEDIR}${PREFIX}/lib/pegasus/bin/loadxml
	${INSTALL_PROGRAM} ${PEGASUS_HOME}/bin/WSMANInvokeMethod ${STAGEDIR}${PREFIX}/lib/pegasus/bin/WSMANInvokeMethod
	${INSTALL_PROGRAM} ${PEGASUS_HOME}/lib/libpegdynlistener.so.1 ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegdynlistener.so.1
	${LN} -sf ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegdynlistener.so.1 ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegdynlistener.so
	${LN} -sf ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegquerycommon.so.1 ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegquerycommon.so
	${LN} -sf ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegqueryexpression.so.1 ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegqueryexpression.so
	${LN} -sf ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegrepository.so.1 ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegrepository.so
	${LN} -sf ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegcql.so.1 ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegcql.so
	${LN} -sf ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegwql.so.1 ${STAGEDIR}${PREFIX}/lib/pegasus/lib/libpegwql.so
	${INSTALL_SCRIPT} ${WRKDIR}/chksrc ${STAGEDIR}${PREFIX}/bin/chksrc
	${INSTALL_SCRIPT} ${WRKDIR}/cimauth ${STAGEDIR}${PREFIX}/bin/cimauth
	${INSTALL_SCRIPT} ${WRKDIR}/cimcli ${STAGEDIR}${PREFIX}/bin/cimcli
	${INSTALL_SCRIPT} ${WRKDIR}/cimconfig ${STAGEDIR}${PREFIX}/bin/cimconfig
	${INSTALL_SCRIPT} ${WRKDIR}/cimcrl ${STAGEDIR}${PREFIX}/bin/cimcrl
	${INSTALL_SCRIPT} ${WRKDIR}/cimlistener ${STAGEDIR}${PREFIX}/bin/cimlistener
	${INSTALL_SCRIPT} ${WRKDIR}/cimmof ${STAGEDIR}${PREFIX}/bin/cimmof
	${INSTALL_SCRIPT} ${WRKDIR}/cimmofl ${STAGEDIR}${PREFIX}/bin/cimmofl
	${INSTALL_SCRIPT} ${WRKDIR}/cimperf ${STAGEDIR}${PREFIX}/bin/cimperf
	${INSTALL_SCRIPT} ${WRKDIR}/cimprovagt ${STAGEDIR}${PREFIX}/bin/cimprovagt
	${INSTALL_SCRIPT} ${WRKDIR}/cimprovider ${STAGEDIR}${PREFIX}/bin/cimprovider
	${INSTALL_SCRIPT} ${WRKDIR}/cimreparchive ${STAGEDIR}${PREFIX}/bin/cimreparchive
	${INSTALL_SCRIPT} ${WRKDIR}/cimserver ${STAGEDIR}${PREFIX}/bin/cimserver
	${INSTALL_SCRIPT} ${WRKDIR}/cimsub ${STAGEDIR}${PREFIX}/bin/cimsub
	${INSTALL_SCRIPT} ${WRKDIR}/cimtrust ${STAGEDIR}${PREFIX}/bin/cimtrust
	${INSTALL_SCRIPT} ${WRKDIR}/ipinfo ${STAGEDIR}${PREFIX}/bin/cimipinfo
	${INSTALL_SCRIPT} ${WRKDIR}/loadxml ${STAGEDIR}${PREFIX}/bin/cimloadxml
	${INSTALL_SCRIPT} ${WRKDIR}/osinfo ${STAGEDIR}${PREFIX}/bin/cimosinfo
	${INSTALL_SCRIPT} ${WRKDIR}/repupgrade ${STAGEDIR}${PREFIX}/bin/cimrepupgrade
	${INSTALL_SCRIPT} ${WRKDIR}/tomof ${STAGEDIR}${PREFIX}/bin/tomof
	${INSTALL_SCRIPT} ${WRKDIR}/wbemexec ${STAGEDIR}${PREFIX}/bin/wbemexec
	@${ECHO} "Installing Configuration Files"
	${INSTALL_SCRIPT} ${WRKDIR}/cimserverd ${STAGEDIR}${PREFIX}/etc/rc.d/cimserverd
	${INSTALL_DATA} ${PEGASUS_HOME}/server.pem ${STAGEDIR}${PREFIX}/etc/pegasus/server.pem
	${INSTALL_DATA} ${PEGASUS_HOME}/cert.pem ${STAGEDIR}${PREFIX}/etc/pegasus/cert.pem
	${INSTALL_DATA} ${PEGASUS_HOME}/cimserver.rnd ${STAGEDIR}${PREFIX}/etc/pegasus/cimserver.rnd
	${INSTALL_DATA} ${PEGASUS_HOME}/client.pem ${STAGEDIR}${PREFIX}/etc/pegasus/client.pem
	${INSTALL_DATA} ${PEGASUS_HOME}/client_cert.pem ${STAGEDIR}${PREFIX}/etc/pegasus/client_cert.pem
	${INSTALL_DATA} ${PEGASUS_HOME}/client_file.pem	${STAGEDIR}${PREFIX}/etc/pegasus/client_file.pem
	${INSTALL_DATA} ${PEGASUS_HOME}/file.pem ${STAGEDIR}${PREFIX}/etc/pegasus/file.pem
	${INSTALL_DATA} ${PEGASUS_HOME}/ssl.cnf ${STAGEDIR}${PREFIX}/etc/pegasus/ssl.cnf
	${INSTALL_DATA} ${PEGASUS_HOME}/ssl.rnd ${STAGEDIR}${PREFIX}/etc/pegasus/ssl.rnd
	${INSTALL_DATA}	${WRKDIR}/cimserver_planned.conf ${STAGEDIR}${PREFIX}/etc/pegasus/cimserver_planned.conf
	${INSTALL_DATA} ${WRKDIR}/cimserver_planned.conf ${STAGEDIR}${PREFIX}/etc/pegasus/cimserver_current.conf
	${INSTALL_DATA} ${WRKDIR}/cimserver_planned.conf ${STAGEDIR}${PREFIX}/etc/pegasus/cimserver.conf
	@${ECHO} "Installing Custom Headers"
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Config
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Query
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Query/QueryCommon
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Query/QueryExpression
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/pegasus/include/Pegasus/Repository
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Provider/CIMInstanceQueryProvider.h ${STAGEDIR}${PREFIX}/include/Pegasus/Provider/CIMInstanceQueryProvider.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/MessageLoader.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/MessageLoader.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Formatter.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Formatter.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Buffer.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Buffer.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/ArrayInternal.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/ArrayInternal.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/ArrayImpl.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/ArrayImpl.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/ArrayRep.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/ArrayRep.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/AtomicInt.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/AtomicInt.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Memory.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Memory.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/InternalException.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/InternalException.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/PegasusAssert.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/PegasusAssert.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/HashTable.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/HashTable.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/AutoPtr.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/AutoPtr.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/PegasusVersion.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/PegasusVersion.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/ReadWriteSem.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/ReadWriteSem.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Semaphore.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Semaphore.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Threads.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Threads.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Mutex.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Mutex.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Magic.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Magic.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/HostAddress.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/HostAddress.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Socket.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Socket.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Network.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Network.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Constants.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Constants.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/Pair.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/Pair.h
	${INSTALL_DATA} ${WRKSRC}/src/Pegasus/Common/DeclContext.h ${STAGEDIR}${PREFIX}/include/Pegasus/Common/DeclContext.h
	${INSTALL_DATA} ${WRKDIR}/wbem ${STAGEDIR}${PREFIX}/etc/pam.d/wbem
	@${ECHO} "Installing Repository Files"
	@(cd ${PEGASUS_HOME} && ${TAR} pczf repository-${PEGASUS_CIM_SCHEMA}.tar.gz repository)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pegasus
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pegasus/providers
	${INSTALL_DATA} ${PEGASUS_HOME}/repository-${PEGASUS_CIM_SCHEMA}.tar.gz ${STAGEDIR}${PREFIX}/share/pegasus/repository-${PEGASUS_CIM_SCHEMA}.tar.gz
	${RM} -rf ${PEGASUS_HOME}/stagingDir/${PREFIX}/share/pegasus/repository
	cd ${PEGASUS_HOME}/stagingDir/${PREFIX}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share	
	@(cd ${PEGASUS_HOME}/www && ${CP} -R * ${STAGEDIR}${PREFIX}/www/pegasus)

.include <bsd.port.post.mk>
