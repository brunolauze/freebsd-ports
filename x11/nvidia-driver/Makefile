# Created by: Stijn Hoop <stijn@win.tue.nl>
# $FreeBSD: head/x11/nvidia-driver/Makefile 346990 2014-03-04 06:20:41Z danfe $

PORTNAME=	nvidia-driver
DISTVERSION?=	337.12
# Always try to set PORTREVISION as it can be overridden by the slave ports
PORTREVISION?=	0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_NVIDIA}
# MASTER_SITE_SUBDIR has to be set later because it depends on NVVERSION
DISTNAME=	NVIDIA-FreeBSD-x86${ARCH_SUFX}-${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

LICENSE=	NVIDIA
LICENSE_NAME=	License For Customer Use of NVIDIA Software
LICENSE_FILE=	${WRKSRC}/doc/license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ARCH_SUFX=	${ARCH:S/i386//:S/amd/_/}
USES=		kmod uidfix
USE_XORG=	xorg-server
USE_GL=		gl
USE_LDCONFIG=	yes

# NVIDIA_ROOT is not set in src/Makefile, which results in bogus -I/src
# passed to compiler and broken build on HEAD since r221320 when option
# -Wmissing-include-dirs was added for kernel sources.  Until properly
# fixed upstream (across all versions, including legacy ones), use this
# hack below to universally set NVIDIA_ROOT.  Also provide X11BASE value
# since it is still used by legacy drivers.
MAKE_ENV=	NVIDIA_ROOT=${WRKSRC} X11BASE=${LOCALBASE}
SUB_FILES=	pkg-deinstall pkg-install pkg-message
DOCSDIR=	${PREFIX}/share/doc/NVIDIA_GLX-1.0
MODULESDIR=	lib/xorg/modules
PORTDOCS=	*

.if ${DISTVERSION:C/[0-9]+//g} == ".."		# major.minor.update
NVVERSION=	${DISTVERSION:S/.//g}
.else						# major.minor
NVVERSION=	${DISTVERSION:S/.//g}00
.endif

.if ${NVVERSION} >= 1952200
MASTER_SITE_SUBDIR=	XFree86/FreeBSD-x86${ARCH_SUFX}/${DISTVERSION}
ONLY_FOR_ARCHS=	i386 amd64
.else
MASTER_SITE_SUBDIR=	freebsd/${DISTVERSION}
ONLY_FOR_ARCHS=	i386
.endif

.if ${NVVERSION} <= 1904200
EXTRA_PATCHES=	${FILESDIR}/legacy-patch-mk-nvidia.lib.mk
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-mk-nvidia.lib.mk
.endif

.if ${NVVERSION} >= 3312000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-x11-driver-Makefile
.else
EXTRA_PATCHES+=	${FILESDIR}/legacy-patch-x11-driver-Makefile
.endif

# Fix recent arbitrary memory access vulnerability in legacy drivers
.if ${NVVERSION} <= 1905300
.  if ${NVVERSION} != 1731435
EXTRA_PATCHES+=	${FILESDIR}/security-patch-CVE-2012-0946
.  endif
EXTRA_PATCHES+=	${FILESDIR}/security-patch-CVE-2012-4225
.endif

OPTIONS_DEFINE=	ACPI_PM LINUX DOCS
OPTIONS_DEFAULT=	LINUX

ACPI_PM_DESC=		ACPI Power Management support
LINUX_DESC=		Linux compatibility support

.if ${NVVERSION} < 3101400
OPTIONS_DEFINE+=	FREEBSD_AGP
FREEBSD_AGP_DESC=	Use FreeBSD AGP GART driver
.endif

.if ${NVVERSION} >= 1952200
OPTIONS_DEFINE+=	WBINVD
WBINVD_DESC=		Flush CPU caches directly with WBINVD
.endif

PLIST_SUB+=	LINUXBASE=${LINUXBASE} SHLIB_VERSION=${PORTVERSION} \
		MODULESDIR=${MODULESDIR}

.include <bsd.port.options.mk>

# FreeBSD src SVN r254138 had broken 71.86.xx legacy series :(
.if ${OSVERSION} > 1000041 && ${NVVERSION} <= 718615
BROKEN=		does not compile
.endif

.if ${PORT_OPTIONS:MLINUX}
CONFLICTS=	linux[-_]dri-[0-9]* linux-f10-dri-[0-9]*
USE_LINUX=	yes
PLIST_SUB+=	LINUX=""
.else
PLIST_SUB+=	LINUX="@comment "
# Propagate WITHOUT_LINUX variable down to inner Makefiles
MAKE_ENV+=	WITHOUT_LINUX=yes
.endif

.if ${NVVERSION} < 1952200
# ABI version is hardcoded inside the binary, so specify it explicitly here
LIB_DEPENDS=	libm.so.3:${PORTSDIR}/misc/compat5x
.endif

post-patch: .SILENT
# We should support -CURRENT: kill the check
	${REINPLACE_CMD} -e '24,26d' ${WRKSRC}/src/nv-freebsd.h
# Adjust legacy drivers for updated d_mmap() since FreeBSD src SVN r201223
.if ${OSVERSION} > 900005 && ${NVVERSION} < 1952200
	${REINPLACE_CMD} -e 's/vm_offset_t offset/vm_ooffset_t offset/ ; \
		s/vm_offset_t \*address/vm_paddr_t *address/ ; \
		s/int nprot/&, vm_memattr_t *memattr/' \
			${WRKSRC}/src/nvidia_dev.c
.endif
# In the legacy drivers: remove page queue locking and add page locking
# around vm_page_(un)wire() after FreeBSD src SVN r207410, r207617, and
# r207644; also remove page queue locking around vm_page_wakeup() after
# FreeBSD src SVN r163622
.if ${OSVERSION} > 900011 && ${NVVERSION} < 3046400
	${REINPLACE_CMD} -E '/vm_page_(un)?lock_queues\(\);/d ; \
		s/(vm_page_(un)?wire\()([^,]+)(, 0)?(\);)/vm_page_lock(\3); & vm_page_unlock(\3);/' \
			${WRKSRC}/src/nvidia_subr.c
.endif
# Catch up legacy drivers with FreeBSD src SVN r225617
.if ${OSVERSION} > 900043 && ${NVVERSION} < 1952200
	${REINPLACE_CMD} -e '/return/s/ioctl/sys_&/' \
		${WRKSRC}/src/nvidia_linux.c
.endif
# Adjust Linux headers #include's after FreeBSD src SVN r246085
.if ${OSVERSION} > 1000027 && ${NVVERSION} >= 964323
	${REINPLACE_CMD} -E '/#include "machine\/\.\.\/linux(32)?\/linux.h"/ \
		{ x ; s/.*/#include "machine\/..\/..\/compat\/linux\/linux_ioctl.h"/ ; H ; x ; }' \
			${WRKSRC}/src/nvidia_linux.c
.endif
# Adjust vm_object locking after FreeBSD src SVN r248084
.if ${OSVERSION} > 1000029
	${REINPLACE_CMD} -e '/#include <vm\/vm_object.h>/ \
		{ x ; s/.*/#include <sys\/rwlock.h>/ ; G ; }' \
			${WRKSRC}/src/nv-freebsd.h
	${REINPLACE_CMD} -E 's/(VM_OBJECT_)(UN)?(LOCK)/\1W\2\3/' \
		${WRKSRC}/src/nvidia_subr.c
.endif
# Adjust kmem(9) calls after FreeBSD src SVN r254025
.if ${OSVERSION} > 1000040
	${REINPLACE_CMD} -e '/kmem_/s/kernel_map/kernel_arena/' \
		${WRKSRC}/src/nvidia_subr.c
.endif
# Adopt to cap_rights_t type change in FreeBSD src SVN r255219
.if ${OSVERSION} > 1000052
	${REINPLACE_CMD} -e 's/u_long cmd;/& cap_rights_t rights;/ ; \
		s/CAP_IOCTL/cap_rights_init(\&rights, &)/' \
			${WRKSRC}/src/nvidia_linux.c
.endif
# Argument count of vm_map_find() changed in FreeBSD src SVN r255426
.if ${OSVERSION} > 1000054
	${REINPLACE_CMD} -e 's/virtual_address, size,/& 0,/' \
		${WRKSRC}/src/nvidia_subr.c
.endif
# Fix stack buffer overflow in nvidia_sysctl_bus_type()
.if ${NVVERSION} < 3192300
	${REINPLACE_CMD} -E '/bus_type\[4\]/d ; \
		s/sprintf\(bus_type, (".+")/return SYSCTL_OUT(req, \1, sizeof(\1)/ ; \
		/return SYSCTL_OUT\(req, bus_type/d' \
			${WRKSRC}/src/nvidia_sysctl.c
.endif
# Unbreak the build of 173.14.xx legacy series on recent -CURRENT
.if ${NVVERSION} < 1952200 && ${NVVERSION} >= 1690400
	${REINPLACE_CMD} -E 's/os_(alloc|free)_contig_pages/NV_API_CALL &/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
# Process OPTIONS
.if ${PORT_OPTIONS:MFREEBSD_AGP}
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_OS_AGP)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if ${PORT_OPTIONS:MACPI_PM}
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_ACPI_PM)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if ! ${PORT_OPTIONS:MLINUX}
	${REINPLACE_CMD} -E 's/define (NV_SUPPORT_LINUX_COMPAT)/undef \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if ${PORT_OPTIONS:MWBINVD}
	${REINPLACE_CMD} -E 's/undef (NV_USE_WBINVD)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
	${REINPLACE_CMD} -e 's/exists(\/.*/& \&\& !defined(WITHOUT_LINUX)/' \
		${WRKSRC}/lib/Makefile
# Do not install VDPAU libraries which are provided by `multimedia/libvdpau'
# port for a while now
.if ${NVVERSION} >= 1802900
	${REINPLACE_CMD} -e '/libvdpau[[:blank:]_][^n]/d ; \
		s/name libvdpau/&_nvidia/' ${WRKSRC}/lib/Makefile
.endif
# Do not build any binaries (native nvidia-settings and nvidia-xconfig are
# provided by corresponding ports) and manual pages
.if ${NVVERSION} < 974600 || ${NVVERSION} >= 1952200
	${REINPLACE_CMD} -E 's/(extension).*/\1/' ${WRKSRC}/x11/Makefile
.else
	${REINPLACE_CMD} -E 's/(lib).*/\1/' ${WRKSRC}/x11/Makefile
.endif
	${REINPLACE_CMD} -e '/bin/d ; /man/d' ${WRKSRC}/x11/Makefile
# Conditionally install documentation (but you generally want it)
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -E 's/(x11).*/\1/ ; /doc/d' ${WRKSRC}/Makefile
.endif
# Adjust installation paths of some conflicting files (shared also between
# libGL and xorg-server) to ease package manager work, esp. with pkgng
	${REINPLACE_CMD} -e '/LIBDIR/s:xorg/modules/extensions:&/.nvidia:' \
		${WRKSRC}/x11/extension/Makefile
	${REINPLACE_CMD} -e '/LIBDIR/s:lib:&/.nvidia:' \
		${WRKSRC}/lib/libGL/Makefile
# Do not execute afterinstall target (prevent automatic module registration
# and "smart" installation of conflicting files heuristics)
	${REINPLACE_CMD} -e 's/afterinstall/&_dontexecute/' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/beforeinstall/&_dontexecute/' \
		${WRKSRC}/lib/Makefile ${WRKSRC}/src/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MODULESDIR}/drivers \
		${STAGEDIR}${PREFIX}/${MODULESDIR}/extensions

post-install: .SILENT
	${INSTALL_SCRIPT} ${WRKSRC}/obj/nvidia-bug-report.sh \
		${STAGEDIR}${PREFIX}/bin
# pkg-plist is already overbloated, so use these hacks instead of PLIST_SUB's
.if ${NVVERSION} < 817400
	${REINPLACE_CMD} -e '/libnvidia-cfg/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 974600 || ${NVVERSION} >= 1952200
	${REINPLACE_CMD} -e '/wfb/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 1802900
	${REINPLACE_CMD} -e '/vdpau/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 1851829
	${REINPLACE_CMD} -e '/libcuda/d' ${TMPPLIST}
.endif
.if ${NVVERSION} >= 2565300
	${REINPLACE_CMD} -E 's/libGLcore/libnvidia-glcore/ ; \
		/usr.*(glcore|tls).*so\.1$$/d' ${TMPPLIST}
.endif
.if ${NVVERSION} >= 3101900
	${REINPLACE_CMD} -e '/libXvMCNVIDIA/d' ${TMPPLIST}
.else	# some applications need this symlink (see PR ports/72877)
	${LN} -sf libXvMCNVIDIA.so.1 \
		${STAGEDIR}${PREFIX}/lib/libXvMCNVIDIA_dynamic.so.1
.endif
.if ${NVVERSION} < 3311300 || ${ARCH} == amd64
	${REINPLACE_CMD} -E '/lib(nvidia-)?(EGL|eglcore|GLESv|glsi)/d' \
		${TMPPLIST}
.endif
.if ${NVVERSION} >= 1952200
	${REINPLACE_CMD} -e '/does not support PAE/,+1d' ${PKGMESSAGE}
.endif

# Target below can be used instead of standard `makesum' to correctly
# update distinfo (i.e., keeping other driver version entries intact)
.if ${.TARGETS:Mupdate-distinfo}
DISTINFO_FILE=	${MASTERDIR}/distinfo.new
JOIN?=		/usr/bin/join
.endif

update-distinfo: makesum .SILENT
	${REINPLACE_CMD} -i '' -e '/${DISTNAME:R:R}/s/^/~/' \
		${MASTERDIR}/distinfo ${DISTINFO_FILE}
	${SED} -e '/^~/s/(.*//' ${MASTERDIR}/distinfo | ${JOIN} -a 1 \
		- ${DISTINFO_FILE} | ${SED} -e 's/^~//' \
		> ${MASTERDIR}/distinfo.tmp
	${MV} ${MASTERDIR}/distinfo.tmp ${MASTERDIR}/distinfo
	${RM} ${DISTINFO_FILE}

.include <bsd.port.mk>
