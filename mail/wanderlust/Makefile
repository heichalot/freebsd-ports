# New ports collection makefile for:	Wanderlust
# Date created:		7 Apr 1999
# Whom: 		MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	wanderlust
PORTVERSION=	2.14.0
PORTREVISION=	7
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/elisp/wl/stable/&,} \
		http://www.jpl.org/elips/wl/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	wl-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Yet another message interface on Emacsen

USE_EMACS=	yes

CONFLICTS=	wanderlust-*-2.15.*

.include <bsd.port.pre.mk>

EMACS_W3M_PORT_NAME?=	emacs-w3m
EMACS_W3M_LISP_FILE?=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/w3m/shimbun.el

MIMEUI_PORT_NAME?=	${MIMEUI_PRODUCT}
MIMEUI_PRODUCT=	semi
MIMEUI_VERSION=	1.14
MIMEUI_COOKIE=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}-${MIMEUI_VERSION}.FreeBSD-packages

BUILD_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}

.if (${EMACS_NAME} == "emacs") && (${EMACS_MAJOR_VER} >= 22)
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/x-face-e21.el:${PORTSDIR}/mail/x-face-e21
.endif

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-WL-MK ${PATCHDIR}/extra-patch-elmo:elmo-version.el
.endif

.if exists(${EMACS_W3M_LISP_FILE})
BUILD_DEPENDS+=	${EMACS_W3M_LISP_FILE}:${PORTSDIR}/www/${EMACS_W3M_PORT_NAME}
RUN_DEPENDS+=	${EMACS_W3M_LISP_FILE}:${PORTSDIR}/www/${EMACS_W3M_PORT_NAME}
SHIMBUN=	""
.else
SHIMBUN=	"@comment "
.endif

ALL_TARGET?=	all info
INSTALL_TARGET?=	install install-info
INFODIR=	${PREFIX}/info
UTILSDIR?=	${EMACS_VERSION_SITE_LISPDIR}/wl
WL_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/wl
WL_ICONDIR=	${EMACS_LIBDIR_WITH_VER}/etc/wl/icons
STARTUPDIR?=	${EMACS_VERSION_SITE_LISPDIR}

DIRSECTION=	"The Emacs editor and associated tools"
PORTDOCDIR=	share/doc/wanderlust
PORTDOCDIR_JA=	share/doc/ja/wanderlust
DOCS=		README NEWS doc/wl.texi
DOCS_JA=	README.ja NEWS.ja doc/wl-ja.texi
SAMPLESDIR=	share/examples/wanderlust
SAMPLESLANG=	en ja
SAMPLES=	dot.addresses dot.folders dot.wl
UTILS=		bbdb-wl.el

PLIST_SUB+=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		DIRSECTION=${DIRSECTION} \
		STARTUPDIR=${STARTUPDIR} \
		WL_LISPDIR=${WL_LISPDIR} \
		WL_ICONDIR=${WL_ICONDIR} \
		SHIMBUN=${SHIMBUN}
.if (${EMACS_PORT_NAME} == "emacs-devel")
PLIST=		${PKGDIR}/pkg-plist.emacs22
.else
PLIST=		${PKGDIR}/pkg-plist.${EMACS_PORT_NAME}
.endif
WRK_STARTUP_FILE=	${WRKDIR}/wanderlust-startup.el
MAKE_ARGS+=	EMACS=${EMACS_CMD} XEMACS=${EMACS_CMD} \
		LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
		FLAGS="-batch -q -no-site-file -l ${WRK_STARTUP_FILE:C/\/\/*/\//g}"
.if defined(EMACS_PACKAGESDIR)
MAKE_ARGS+=	PACKAGEDIR=${PREFIX}/${EMACS_PACKAGESDIR}
.else
MAKE_ARGS+=	INFODIR=${INFODIR}
.endif

post-extract:
	@${CP} ${FILESDIR}/WL-CFG ${WRKSRC}

.if (${EMACS_PORT_NAME} == "emacs-devel")
STARTUP_TMPL=	${FILESDIR}/wanderlust-startup.emacs22.el.tmpl
.else
STARTUP_TMPL=	${FILESDIR}/wanderlust-startup.${EMACS_PORT_NAME}.el.tmpl
.endif

post-configure:
	@${SED} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%EMACS_LIBDIR%%,${EMACS_LIBDIR},g" \
		-e "s,%%EMACS_LIBDIR_WITH_VER%%,${EMACS_LIBDIR_WITH_VER},g" \
		-e "s,%%EMACS_PACKAGESDIR%%,${EMACS_PACKAGESDIR},g" \
		< ${STARTUP_TMPL} > ${WRKDIR}/wanderlust-startup.el

pre-build:
.if defined(EMACS_PACKAGESDIR)
	@${CP} ${FILESDIR}/_pkg.el ${WRKSRC}
.endif

post-install:
.if !exists(${EMACS_W3M_LISP_FILE})
.if defined(EMACS_PACKAGESDIR)
	${INSTALL_DATA} ${WRKSRC}/elmo/elmo-shimbun.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
.else
	${INSTALL_DATA} ${WRKSRC}/elmo/elmo-shimbun.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/wl
.endif
.endif
.if !defined(EMACS_PACKAGESDIR)
	@${MAKE} install-info
.endif
.if !defined(NOPORTDOCS)
	@${MAKE} install-docs
.endif
	@${MAKE} install-samples
	@${MAKE} install-utils
.if defined(EMACS_PACKAGESDIR)
	@${MAKE} install-manifest
.endif
	@${CAT} ${PKGMESSAGE}

# local targets
install-info:
	@install-info --section=${DIRSECTION} ${WRKSRC}/doc/wl.info ${INFODIR}/dir
	@install-info --section=${DIRSECTION} ${WRKSRC}/doc/wl-ja.info ${INFODIR}/dir

install-docs:
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	@${MKDIR} ${PREFIX}/${PORTDOCDIR_JA}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR}
.endfor
.for i in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR_JA}
.endfor

install-samples:
.for l in ${SAMPLESLANG}
	${MKDIR} ${PREFIX}/${SAMPLESDIR}/$l
	for i in ${SAMPLES} ; do \
		${INSTALL_DATA} ${WRKSRC}/samples/$l/$$i ${PREFIX}/${SAMPLESDIR}/$l; \
	done
.endfor
	${MKDIR} ${PREFIX}/share/wanderlust
	${INSTALL_DATA} ${WRKSRC}/etc/ja.Emacs ${PREFIX}/share/wanderlust

install-utils:
	@${MKDIR} ${PREFIX}/${UTILSDIR}
.for i in ${UTILS}
	${INSTALL_DATA} ${WRKSRC}/utils/${i} ${PREFIX}/${UTILSDIR}
.endfor
	@${MKDIR} ${PREFIX}/${STARTUPDIR}
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${STARTUPDIR}

install-manifest:
	@${CAT} ${PKGDIR}/pkg-plist.${EMACS_PORT_NAME} | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s!^%%EMACS_PACKAGESDIR%%!!" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} ${PREFIX}/${EMACS_PACKAGESDIR}/pkginfo/
	@${INSTALL_DATA} ${FILESDIR}/_pkg.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl

.include <bsd.port.post.mk>
