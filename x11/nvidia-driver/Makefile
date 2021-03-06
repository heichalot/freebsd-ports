# New ports collection makefile for:	nvidia-driver (latest and master port)
# Date created:				4 December 2002
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	nvidia-driver
DISTVERSION?=	195.36.15
PORTREVISION?=	0			# As a reminder it can be overridden
CATEGORIES=	x11 kld
MASTER_SITES=	${MASTER_SITE_NVIDIA}
ARCH_SUFX=	${ARCH:S/i386//:S/amd/_/}
# MASTER_SITE_SUBDIR has to be set later because it depends on NVVERSION
DISTNAME=	NVIDIA-FreeBSD-x86${ARCH_SUFX}-${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NVidia graphics card binary drivers for hardware OpenGL rendering

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel
USE_GL=		gl
USE_LDCONFIG=	yes
SUB_FILES+=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/NVIDIA_GLX-1.0
MODULESDIR=	lib/xorg/modules
PORTDOCS=	*

# Starting with version 1.0-7667, NVidia has dropped support for numerous
# "legacy" GPUs.  Consult NVidia README (the Appendix) to find out whether
# you need to use legacy driver version and install one of corresponding
# `x11/nvidia-driver-71', `x11/nvidia-driver-96', or `x11/nvidia-driver-173'
# slave ports.
#
# XXX Until NVidia starts to name their releases consistently, employ this
# ugly hack below to derive NVVERSION. XXX
#
.if ${DISTVERSION:C/[0-9]+//g} == ".."			# major.minor.update
NVVERSION=	${DISTVERSION:S/.//g}
.else							# major.minor
NVVERSION=	${DISTVERSION:S/.//g}00
.endif

.if ${NVVERSION} >= 1952200
MASTER_SITE_SUBDIR=	XFree86/FreeBSD-x86${ARCH_SUFX}/${DISTVERSION}
ONLY_FOR_ARCHS=	i386 amd64
.else
MASTER_SITE_SUBDIR=	freebsd/${DISTVERSION}
ONLY_FOR_ARCHS=	i386
.endif

OPTIONS=	FREEBSD_AGP	"Use FreeBSD AGP GART driver" off \
		ACPI_PM		"Enable support for ACPI Power Management" off \
		LINUX		"Build with support for Linux compatibility" on
.if ${NVVERSION} >= 1952200
OPTIONS+=	WBINVD		"Enable heavy-weight cache-flush logic" off
.endif

.include <bsd.port.pre.mk>

# XXX Should use ${PKG_INFO} but it does not expand for some reason XXX
#
XSERVVERSION!=	/usr/sbin/pkg_info -qO x11-servers/xorg-server 2>/dev/null || true
LIBGLVERSION!=	/usr/sbin/pkg_info -qO graphics/libGL 2>/dev/null || true

.if empty(XSERVVERSION)
IGNORE=		needs an X server implementation installed
.endif

PLIST_SUB+=	XSERVVERSION=${XSERVVERSION} LIBGLVERSION=${LIBGLVERSION} \
		LINUXBASE=${LINUXBASE} SHLIB_VERSION=${PORTVERSION} \
		MODULESDIR=${MODULESDIR}

.if !defined(WITHOUT_LINUX)
CONFLICTS=	linux-dri-[0-9]* linux-f10-dri-[0-9]* linux-f8-dri-[0-9]* \
		linux_dri-[0-9]* linux_dri-devel-[0-9]*
USE_LINUX=	yes
PLIST_SUB+=	LINUX=""
.else
PLIST_SUB+=	LINUX="@comment "
# Propagate WITHOUT_LINUX variable down to inner Makefiles
MAKE_ENV+=	WITHOUT_LINUX=yes
.endif

.if ${OSVERSION} < 702106 && ${NVVERSION} >= 1952200
IGNORE=		requires fairly recent FreeBSD-STABLE, or FreeBSD-CURRENT
.endif

.if ${NVVERSION} < 1952200
LIB_DEPENDS+=	m.3:${PORTSDIR}/misc/compat5x
.endif

post-patch: .SILENT
# We should support -CURRENT: kill the check
	${REINPLACE_CMD} '24,26d' ${WRKSRC}/src/nv-freebsd.h
# Adjust for updated d_mmap() in recent -CURRENT
.if ${OSVERSION} > 900005 && ${NVVERSION} < 1952200
	${REINPLACE_CMD} 's/vm_offset_t offset/vm_ooffset_t offset/ ; \
		s/vm_offset_t \*address/vm_paddr_t *address/ ; \
		s/int nprot/&, vm_memattr_t *memattr/' \
			${WRKSRC}/src/nvidia_dev.c
.endif
.if defined(WITH_FREEBSD_AGP)
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_OS_AGP)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITH_ACPI_PM)
	${REINPLACE_CMD} -E 's/undef (NV_SUPPORT_ACPI_PM)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITHOUT_LINUX)
	${REINPLACE_CMD} -E 's/define (NV_SUPPORT_LINUX_COMPAT)/undef \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
.if defined(WITH_WBINVD)
	${REINPLACE_CMD} -E 's/undef (NV_USE_WBINVD)/define \1/' \
		${WRKSRC}/src/nv-freebsd.h
.endif
# Don't build any binaries (nvidia-settings and nvidia-xconfig) and manuals
.if ${NVVERSION} < 974600 || ${NVVERSION} >= 1952200
	${REINPLACE_CMD} -E 's/(extension).*/\1/' ${WRKSRC}/x11/Makefile
.else
	${REINPLACE_CMD} -E 's/(lib).*/\1/' ${WRKSRC}/x11/Makefile
.endif
	${REINPLACE_CMD} '/bin/d ; /man/d' ${WRKSRC}/x11/Makefile
# Conditionally install documentation (but you generally want it)
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -E 's/(x11).*/\1/ ; /doc/d' ${WRKSRC}/Makefile
.endif
# Do not execute afterinstall target (prevent automatic module registration)
	${REINPLACE_CMD} -e 's/afterinstall/dontexecute/' ${WRKSRC}/Makefile

pre-su-install:
# XXX This port silently assumes PREFIX == LOCALBASE XXX
	@${MKDIR} ${PREFIX}/${MODULESDIR}/drivers

post-install:
# pkg-plist is already overbloated, so use these hacks instead of PLIST_SUB's
.if ${NVVERSION} < 817400
	@${REINPLACE_CMD} '/libnvidia-cfg/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 974600 || ${NVVERSION} >= 1952200
	@${REINPLACE_CMD} '/wfb/d' ${TMPPLIST}
.endif
.if ${NVVERSION} < 1802900
	@${REINPLACE_CMD} '/vdpau/d' ${TMPPLIST}
.else
	@${MKDIR} ${PREFIX}/include/vdpau
	@${LN} -sf ${DOCSDIR}/vdpau*.h ${PREFIX}/include/vdpau
.endif
.if ${NVVERSION} < 1851829
	@${REINPLACE_CMD} '/libcuda/d' ${TMPPLIST}
.endif
# Some applications need this symlink (see PR ports/72877)
	@${LN} -sf libXvMCNVIDIA.so.1 ${PREFIX}/lib/libXvMCNVIDIA_dynamic.so.1
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
