# New ports collection makefile for: OpenOffice.org
# Date created:		28 February 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME?=	openoffice.org
PORTVERSION?=	${OOOVERSION}
PORTREVISION=	2
CATEGORIES+=	editors java
MASTER_SITES+=	http://ooopackages.good-day.net/pub/OpenOffice.org/sources/ \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		${MASTER_SITE_MOZILLA:S/$/:mozsrc/} \
		http://tools.openoffice.org/unowinreg_prebuild/680/:unowinreg
MASTER_SITE_SUBDIR+=	mozilla/releases/mozilla${MOZILLA_VERSION}/source/:mozsrc
DISTFILES+=	${OOOSRC} unowinreg.dll:unowinreg
.if defined(WITH_GPC)
DISTFILES+=	gpc231.tar.Z:gpc
.endif
EXTRACT_ONLY=	${OOOSRC}

#de facto maintainer is maho@FreeBSD.org
#patch submitters must sign SCA; see http://porting.openoffice.org/freebsd/#policy
MAINTAINER=	openoffice@FreeBSD.org
COMMENT?=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser

CONFLICTS=	cppunit*

OOOVERSION=	2.4.3
NO_LATEST_LINK=	yes
USE_GNOME=	desktopfileutils gtk20
MOZILLA_VERSION=	1.7.5
MOZILLA_SOURCE=		mozilla-source-${MOZILLA_VERSION}.tar.gz
.if !defined(WITHOUT_MOZILLA)
DISTFILES+=	${MOZILLA_SOURCE}:mozsrc
USE_GNOME+=	libidl
.endif

.if defined(WITH_KDE)
USE_KDELIBS_VER=	3
.endif
USE_XORG=	x11 ice xaw xau xext xrender xrandr \
		xi xt xcursor xdamage xcomposite xfixes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_BZIP2=	yes
WITHOUT_CPU_CFLAGS=	true
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VENDOR=	freebsd bsdjava openjdk
.if (${OSVERSION} >= 700000)
JAVA_VERSION=	1.5 1.6
.else
JAVA_VERSION=	1.4 1.5 1.6
.endif

.include <${FILESDIR}/Makefile.localized>

ONLY_FOR_ARCHS=	i386 amd64

.if ${ARCH} == amd64
FREEBSD_ENV_SET=	FreeBSDAMDEnv.Set
.else
FREEBSD_ENV_SET=	FreeBSDX86Env.Set
.endif

MILESTONE?=		21
OOOTAG?=		OOH680_m${MILESTONE}
OOOSRC?=		OOo_${OOOTAG}_source${EXTRACT_SUFX}
INSTALLATION_BASEDIR?=	openoffice.org-${OOOVERSION}
EXECBASE?=		openoffice.org-${OOOVERSION}
DIST_SUBDIR=		openoffice.org2
SIMPLEOSVER=		${OSREL:C/\.//g}
.if ${ARCH} == amd64
PACKAGE_BASENAME=	OOo_${OOOVERSION}_${OPSYS}${SIMPLEOSVER}X86-64
.else
PACKAGE_BASENAME=	OOo_${OOOVERSION}_${OPSYS}${SIMPLEOSVER}Intel
.endif

LOCALIZED_LANG?=	en-US
# FIXME (Somehow INDEX build fails)
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=		${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX=		-${LANG_SUFFIX}
.endif

RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CCACHE_PREFIX=	ccache
OOOCC=		${CCACHE_PREFIX} ${CC}
OOOCXX=		${CCACHE_PREFIX} ${CXX}
.else
OOOCC=		${CC}
OOOCXX=		${CXX}
.endif
CONFIGURE_ENV+=	CC="${OOOCC}" CXX="${OOOCXX}"		\
		CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib"

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gpatch:${PORTSDIR}/devel/patch \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		bash:${PORTSDIR}/shells/bash \
		imake:${PORTSDIR}/devel/imake \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		ant:${PORTSDIR}/devel/apache-ant

.if !defined(WITH_GPC)
LIB_DEPENDS+=	art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl
.endif

USE_BISON=	build
GNU_CONFIGURE=	yes
WRKSRC?=		${WRKDIR}/${OOOTAG}
CONFIGURE_WRKSRC=	${WRKSRC}/config_office
TCSH?=		/bin/tcsh
SUB_FILES=	pkg-message
SUB_LIST=	EXECBASE=${EXECBASE} INSTALLATION_BASEDIR=${INSTALLATION_BASEDIR} OOOTAG=${OOOTAG} OOOVERSION=${OOOVERSION}

CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp		\
			--with-gnu-patch=${LOCALBASE}/bin/gpatch	\
			--enable-crashdump=yes				\
			--with-system-zlib				\
			--with-system-stdlibs				\
			--with-epm=internal

.if ${ARCH} == amd64
WITHOUT_MOZILLA=	yes
.endif
.if (${OSVERSION} <= 602102)
EXTRA_PATCHES+=	${FILESDIR}/rtld-workaround-i66667
.endif
.if !defined(WITH_SYSTEM_FREETYPE) && defined(WITH_TTF_BYTECODE_ENABLED)
EXTRA_PATCHES+=	 ${FILESDIR}/optpatch-freetype
.endif

ICONS=	${WRKSRC}/sysui/desktop/icons

.include <${FILESDIR}/Makefile.knobs>

pre-everything::
# really tweak, extremely useful when you build all localized language versions
# needed after when you build with ALL_LOCALIZED_LANGS.
.if defined(TWEAK_L10N)
	@${RM} -f ${WRKDIR}/.PLIST*
	@${RM} -f ${WRKDIR}/.install_done.*
	@${RM} -f ${WRKDIR}/.package_done.*
	@${RM} -f ${WRKDIR}/.extract_done.*
	@${RM} -f ${WRKDIR}/.patch_done.*
	@${RM} -f ${WRKDIR}/.configure_done.*
	@${RM} -f ${WRKDIR}/.build_done.*
	@${MKDIR} ${WRKDIR}
	@${TOUCH} ${EXTRACT_COOKIE}
	@${TOUCH} ${PATCH_COOKIE}
	@${TOUCH} ${CONFIGURE_COOKIE}
	@${TOUCH} ${BUILD_COOKIE}
.endif

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/unowinreg.dll ${WRKSRC}/external/unowinreg/
.if defined(WITH_GPC)
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/gpc231.tar.Z | ${TAR} xfz -
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/external/gpc/
.endif
.if !defined(WITHOUT_MOZILLA)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_SOURCE} ${WRKSRC}/moz/download
.endif

pre-configure:
#Workaround for gperf. #i85469#
	@${LN} -sf ${LOCALBASE}/bin/gperf ${WRKSRC}/solenv/bin/gperf
	@${LN} -sf ${LOCALBASE}/bin/unzip ${WRKSRC}/solenv/bin/unzip

do-build:
	@cd ${WRKSRC} ; ./bootstrap
# PR:84786 #i53289#
.if !defined(DISABLE_MAKE_JOBS)
	@cd ${WRKSRC} ; ${SETENV} "LANG=C" "LC_ALL=C" ${TCSH} -c "source ${FREEBSD_ENV_SET} ; setenv TMP ${WRKSRC} ; cd instsetoo_native ; build.pl -P${MAKE_JOBS_NUMBER} --all"
.else
	@cd ${WRKSRC} ; ${SETENV} "LANG=C" "LC_ALL=C" ${TCSH} -c "source ${FREEBSD_ENV_SET} ; setenv TMP ${WRKSRC} ; dmake"
.endif
.if ${LOCALIZED_LANG} == "alllangs"
	@${MAKE} languagepack
.endif

do-install:
.if ${LOCALIZED_LANG} == "alllangs"
	@cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/en-US/freebsd-*/ ; ${LS} *.t?z > ${WRKDIR}/INSTALLFILES
	@cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice_languagepack/bsd/install/ ; ${LS} */freebsd*/*.t?z > ${WRKDIR}/LANGPACKFILES
	@${RM} -Rf ${WRKDIR}/tmp
	@${MKDIR} ${WRKDIR}/tmp
	@for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/en-US/freebsd-*/$$i ; \
	done
	@for i in `${CAT} ${WRKDIR}/LANGPACKFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice_languagepack/bsd/install/$$i ;\
	done
	@${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	@cd ${WRKDIR}/tmp/opt/openoffice* ; ${TAR} cf - -C . . | ${TAR} xf - -C ${PREFIX}/${INSTALLATION_BASEDIR}
.else
	@cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/${LOCALIZED_LANG}/freebsd-*/ ; ${LS} *.t?z > ${WRKDIR}/INSTALLFILES
	@${RM} -Rf ${WRKDIR}/tmp
	@${MKDIR} ${WRKDIR}/tmp
	@for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/${LOCALIZED_LANG}/freebsd-*/$$i ; \
	done
	@${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	@cd ${WRKDIR}/tmp/opt/openoffice* ; ${TAR} cf - -C . . | ${TAR} xf - -C ${PREFIX}/${INSTALLATION_BASEDIR}
.endif

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${CP} ${FILESDIR}/openoffice.org-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%OOOTAG%%#${OOOTAG}#g' \
			-e 's#%%OOOVERSION%%#${OOOVERSION}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			${WRKDIR}/openoffice.org-wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice.org-wrapper \
		${PREFIX}/bin/${EXECBASE}
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sbase
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-scalc
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sdraw
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-setofficelang
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-smath
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-simpress
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-spadmin
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-swriter
	@${ECHO_CMD} "" > ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s bin \( -type f -or -type l \) -name "${EXECBASE}*" >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} \( -type f -or -type l \) >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} ${INSTALLATION_BASEDIR} -type d | ${SORT} -r | \
		${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}
	@${REINPLACE_CMD} -e '/^Exec/s/printeradmin/spadmin/' \
			${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg/*.desktop
	@for app in base calc draw impress math printeradmin writer; do \
		${REINPLACE_CMD} -e "s/^Exec.*/Exec=${EXECBASE} -$${app} %U/" \
			-e "s/^Icon.*/Icon=${EXECBASE}-$${app}.png/" \
		${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg/$${app}.desktop ; \
	done
	@${RM} ${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg/*.desktop.bak
	@${RM} -f ${DESKTOPDIR}/${EXECBASE}
	@${MKDIR} ${DESKTOPDIR}
	@${LN} -sf ${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg \
			${DESKTOPDIR}/${EXECBASE}
	@${ECHO_CMD} "share/applications/${EXECBASE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${PREFIX}/bin/update-desktop-database 2>/dev/null || ${TRUE}
	@${ECHO_CMD} "@exec ${PREFIX}/bin/update-desktop-database 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@for dir in `ls ${ICONS}/hicolor | ${GREP} -v CVS`; do \
		for app in base calc draw impress math printeradmin writer; do \
			if [ -r ${ICONS}/hicolor/$${dir}/apps/$${app}.png ]; then \
				${INSTALL_DATA} ${ICONS}/hicolor/$${dir}/apps/$${app}.png \
				    ${PREFIX}/share/icons/hicolor/$${dir}/apps/${EXECBASE}-$${app}.png ; \
				${ECHO_CMD} "share/icons/hicolor/$${dir}/apps/${EXECBASE}-$${app}.png" >> ${TMPPLIST} ; \
			fi \
		done ; \
		for file in `cd ${ICONS}/hicolor/$${dir}/mimetypes; ls *.png`; do \
			${INSTALL_DATA} ${ICONS}/hicolor/$${dir}/mimetypes/$${file} \
			    ${PREFIX}/share/icons/hicolor/$${dir}/mimetypes/ ; \
			${ECHO_CMD} "share/icons/hicolor/$${dir}/mimetypes/$${file}" >> ${TMPPLIST} ; \
		done ; \
	done
	@${PREFIX}/bin/gtk-update-icon-cache -q -f ${PREFIX}/share/icons/hicolor 2>/dev/null || ${TRUE}
	@${ECHO_CMD} "@unexec ${RM} %D/share/icons/hicolor/icon-theme.cache 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${PREFIX}/bin/gtk-update-icon-cache -q -f %D/share/icons/hicolor 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${PREFIX}/bin/gtk-update-icon-cache -q -f %D/share/icons/hicolor 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <${FILESDIR}/Makefile.others>
.include <bsd.port.post.mk>
