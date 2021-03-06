# New ports collection makefile for:	ASTK
# Date created:		Thu Jul 09 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	astk
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	full-src-
DISTVERSIONSUFFIX=	.noarch
CATEGORIES=	cad
MASTER_SITES=	http://www.code-aster.org/V2/UPLOAD/DOC/Telechargement/
.if !defined(CLIENT_SEUL)
PKGNAMESUFFIX=	-serveur
.else
PKGNAMESUFFIX=	-client
.endif
DISTNAME=	aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Graphical interface for Code_Aster (server side)

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITH_ZSH or WITH_BASH or WITH_KSH: select a shell among
#			zsh (default), bash or ksh;
# - WITH_ED: select an editor accepting '-display' (e.g. gvim, nedit);
# - WITH_PBS: PBS (batch scheduler) support is experimental.
#
#-----------------------------------------------------------------------

# There exists a "logical" RUN_DEPENDS towards french/aster and french/eficas
# for the server part, but it is not set to avoid circular dependences.
RUN_DEPENDS+=	${SHELL_INSTALL_ASTER}:${PORTSDIR}/shells/${SHIADEP}

.if !defined(CLIENT_SEUL)
USE_PYTHON=	yes
.endif
NO_BUILD=	yes
REINPLACE_ARGS=	-i ""

ASTER_DISTVERSION=	${ASTER_VER}-4
EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION:S/-/./:R}/SRC

PKGMESSAGE=	${WRKDIR}/pkg-message
LINSTDIR=	aster/ASTK
inst_dir=	${PREFIX}/${LINSTDIR}
aster_dir=	${LOCALBASE}/aster/${vaster}
S_SCRIPTS=	bin/as_run bin/parallel_cp asrun/installation.py	\
		share/codeaster/asrun/data/mpirun_template
S_PYLIBS=	share/codeaster/asrun/examples/alamain.py		\
		asrun/installation.py asrun/devtools.py asrun/repart.py	\
		unittest/client/config_serveurs.in			\
		unittest/others/deprecate.py	unittest/README
C_SCRIPTS=	bin/astk bin/bsf
tools_dir=	${LOCALBASE}/aster/outils
conf_dir=	${WRKSRC}/etc/astkrc

.include <bsd.port.pre.mk>

.if !defined(CLIENT_SEUL)
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/ASTK_SERV
PATCHDIR=	${MASTERDIR}/files
PLIST_SUB=	ASTKDIR=${LINSTDIR}/ASTK_SERV SERV="" CLIENT="@comment "		\
		vaster=${vaster}
PATCH2RM=	bin/as_run bin/parallel_cp etc/asrun etc/profile.csh etc/profile.sh	\
		asrun/config.py
. if exists(${LOCALBASE}/sbin/pbs_server)
WITH_PBS=	yes
. endif
. if exists(${LOCALBASE}/bin/mpirun)
WITH_MPI=	yes
. endif
. if defined(WITH_MPI)
RUN_DEPENDS+=	${HOME_MPI}/bin/mpirun:${PORTSDIR}/net/mpich2
HOME_MPI=	${LOCALBASE}
PLIST_SUB+=	MPI=""
. else
PLIST_SUB+=	MPI="@comment "
. endif
. if defined(WITH_PBS)
RUN_DEPENDS+=	qsub:${PORTSDIR}/sysutils/torque
. endif
.else
RUN_DEPENDS+=	xterm:${PORTSDIR}/x11/xterm						\
		wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/ASTK_CLIENT
PATCHDIR=	${MASTERDIR}/files.client
PLIST_SUB=	ASTKDIR=${LINSTDIR}/ASTK_CLIENT SERV="@comment " CLIENT="" vaster=""	\
		BWidget_DIR=${LINSTDIR}/ASTK_CLIENT/lib/BWidget-${BWidget_VER}
PATCH2RM=	bin/astk bin/bsf etc/astkrc/outils lib/init.tcl lib/tkselecteur.tcl
.endif
FILESDIR=	${PATCHDIR}

SLAVEDIRS=	cad/astk-client

TK_VER?=	8.4
TCL_VER?=	${TK_VER}
SHORT_TK_VER=	${TK_VER:S/.//}
BWidget_VER=	1.7.0

ASTER_VER=	10.1.0
vaster=		STA${ASTER_VER:R}
ETCDIR=		${PREFIX}/aster/etc/codeaster

GIBI=		gibi2003

.if defined(WITH_ZSH)
SHIA=		zsh
.elif defined(WITH_BASH)
SHIA=		bash
.elif defined(WITH_KSH)
SHIA=		ksh93
.elif exists(${LOCALBASE}/bin/zsh)
SHIA=		zsh
.elif exists(${LOCALBASE}/bin/bash)
SHIA=		bash
.elif exists(${LOCALBASE}/bin/ksh93)
SHIA=		ksh93
.else
SHIA=		zsh
.endif
SHIADEP=	${SHIA}

.if !defined(WITH_ED)
. if exists(${LOCALBASE}/bin/nedit)
WITH_ED=	nedit
RUN_DEPENDS+=	${LOCALBASE}/bin/nedit:${PORTSDIR}/editors/nedit
. elif exists(${LOCALBASE}/bin/gvim)
WITH_ED=	gvim
RUN_DEPENDS+=	${LOCALBASE}/bin/gvim:${PORTSDIR}/editors/vim
. elif exists(${LOCALBASE}/bin/emacs)
WITH_ED=	emacs
RUN_DEPENDS+=	${LOCALBASE}/bin/emacs:${PORTSDIR}/editors/emacs
. elif exists(${LOCALBASE}/bin/xemacs)
WITH_ED=	xemacs
RUN_DEPENDS+=	${LOCALBASE}/bin/xemacs:${PORTSDIR}/editors/xemacs
. elif exists(${LOCALBASE}/bin/gedit)
WITH_ED=	gedit
RUN_DEPENDS+=	${LOCALBASE}/bin/gedit:${PORTSDIR}/editors/gedit
. elif exists(${LOCALBASE}/bin/kwrite)
WITH_ED=	kwrite
RUN_DEPENDS+=	${LOCALBASE}/bin/kwrite:${PORTSDIR}/x11/kdebase3
. elif exists(${LOCALBASE}/bin/xedit)
WITH_ED=	xedit
RUN_DEPENDS+=	${LOCALBASE}/bin/xedit:${PORTSDIR}/x11/xedit
. else
WITH_ED=	vi
. endif
.endif

unamesm=	${OPSYS} ${ARCH}
v_ifdef=	${OPSYS:U}
SHELL_INSTALL_ASTER=	${LOCALBASE}/bin/${SHIA}

.if !defined(PACKAGE_BUILDING)
SERVER_NAME!=	${UNAME} -n
HOST_NAME!=	/bin/hostname -s
DOMAIN_NAME=	${SERVER_NAME:S|${HOST_NAME}.||}
.else
SERVER_NAME=	put.your.fdqn
HOST_NAME=	this-hostname
DOMAIN_NAME=	your.domain-name
.endif

.if defined(LANG) && ${LANG:Mfr*} != ""
ASTK_LANG=	FR
.else
ASTK_LANG=	ENG
.endif

post-extract:
	(cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})

pre-configure:
	${RM} ${PATCH2RM:C|^|${WRKSRC}/|:C|$|.orig|}

do-configure:
.if !defined(CLIENT_SEUL)
. for scripts in ${S_SCRIPTS}
	${REINPLACE_CMD} -e "s|?SHELL_EXECUTION?|${SHELL_INSTALL_ASTER}|"	\
		-e "s|?ASTER_ROOT?|${PREFIX}/aster|" ${WRKSRC}/${scripts}
. endfor
	${REINPLACE_CMD} -e "s|?ASTER_VERSION?|${ASTER_VER}|"			\
		 -e 's|#?vers : VVV?|vers : ${vaster}|'				\
		${WRKSRC}/etc/aster
. if defined(WITH_MPI)
	${REINPLACE_CMD} -e "s|?MPIRUN?|${HOME_MPI}/bin/mpirun|"		\
		-e "s|?ASTER_CONFDIR?|${PREFIX}/aster|"				\
		${WRKSRC}/etc/asrun
. endif
. for sc in asrun aster
	${REINPLACE_CMD} -e "s|?IFDEF?|${v_ifdef}|"				\
		-e "s|?EDITOR?|${WITH_ED}|"					\
		-e "s|?TERMINAL?|${LOCALBASE}/bin/xterm|"			\
		-e "s|?NODE?|${HOST_NAME}|"					\
		-e "s|LOCALBASE|${LOCALBASE}|"					\
		${WRKSRC}/etc/${sc}
. endfor
. for sh in sh csh
	${REINPLACE_CMD} -e "s|?ASTER_ROOT?|${LOCALBASE}/aster|"			\
		-e 's|?HOME_PYTHON?|${PYTHONBASE}|'				\
		-e 's|?ASRUN_SITE_PKG?|${PREFIX}/${LINSTDIR}/ASTK_SERV|'	\
		-e 's|?PYTHON_EXE?|${PYTHON_CMD}|'				\
		-e 's|?HOME_MED?|${LOCALBASE}|'					\
		-e 's|?HOME_HDF?|${LOCALBASE}|'					\
		-e "s|?WISH_EXE?|wish${TK_VER}|"				\
		${WRKSRC}/etc/profile.${sh}
. endfor
. for libs in ${S_PYLIBS}
	${REINPLACE_CMD} -e "s|/opt/aster/NEW9|${aster_dir}|"			\
		 -e "s|/opt/aster/NEW10|${aster_dir}|"				\
		-e "s|/opt/aster/ASTK|${inst_dir}|"				\
		-e "s|/opt/aster|${aster_dir}|" ${WRKSRC}/${libs}
. endfor
. if defined(WITH_PBS)
.   for cf in etc/asrun unittest/client/config_serveurs.in
	${REINPLACE_CMD} -e "s|batch : non|batch : oui|"			\
		${WRKSRC}/${cf}
.   endfor
. endif
.else
# CLIENT_SEUL
. for scripts in ${C_SCRIPTS}
	${REINPLACE_CMD} -e "s|?SHELL_EXECUTION?|${SHELL_INSTALL_ASTER}|"	\
		-e "s|?ASTER_ROOT?|${PREFIX}/aster|"				\
		-e "s|wish|wish${TK_VER}|;s|%%inst_dir%%|${inst_dir}|"		\
		${WRKSRC}/${scripts}
. endfor
	${REINPLACE_CMD} -e "s|?vaster?|${vaster}|"					\
		-e "s|?TOOLS_DIR?|${tools_dir}|" ${conf_dir}/outils
	${REINPLACE_CMD} -e "s#?HOME_ASTK?#${inst_dir}#"			\
		-e "s#?TERMINAL?#${LOCALBASE}/bin/xterm#"			\
		-e "s#?FULL_SERVER_NAME?#${SERVER_NAME}#"			\
		-e "s#?SERVER_NAME?#${HOST_NAME}#"				\
		-e "s#?ASTER_ROOT?#${PREFIX}/aster#"				\
		-e "s#?EDITOR?#${WITH_ED}#" ${conf_dir}/config_serveurs
	${REINPLACE_CMD} -e "s#?TERMINAL?#${LOCALBASE}/bin/xterm#"		\
		-e "s#?ASTER_VERSION?#${ASTER_VER}#"				\
		-e "s#langue : ENG#langue : ${ASTK_LANG}#"			\
		-e "s#?DOMAIN_NAME?#${DOMAIN_NAME}#"				\
		-e "s#?EDITOR?#${WITH_ED}#" ${conf_dir}/prefs
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"			\
		${WRKSRC}/lib/tkselecteur.tcl
	${REINPLACE_CMD} -e "s|%%unamesm%%|${unamesm}|"				\
		${WRKSRC}/lib/init.tcl
.endif

do-install:
	${MKDIR} ${inst_dir}
	${CP} -R ${WRKSRC} ${inst_dir}
.if !defined(CLIENT_SEUL)
	${MKDIR} ${ETCDIR}
	${CP} -R ${WRKSRC}/etc/* ${ETCDIR}
	${RM} -rf ${inst_dir}/ASTK_SERV/etc
. for rep in asrun share/codeaster/asrun/examples unittest
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${inst_dir}/ASTK_SERV/${rep}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${inst_dir}/ASTK_SERV/${rep}
. endfor
	(cd ${inst_dir}/ASTK_SERV/unittest/ &&		\
	${SETENV} PYTHONPATH=${PREFIX}/${LINSTDIR}/ASTK_SERV ${PYTHON_CMD} ./config.py)
. if defined(WITH_MPI)
	${ECHO_CMD} "localhost" > ${PREFIX}/aster/aster-mpihosts
. endif
.endif

post-install:
	@${ECHO_MSG}
	@${SED} -e "s|%%ETCDIR%%|${ETCDIR}|"		\
		-e "s|%%inst_dir%%|${inst_dir}|"	\
		-e "s|%%tools_dir%%|${tools_dir}|"	\
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
