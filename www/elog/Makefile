# New ports collection makefile for:   elog
# Date created:        8 July 2006
# Whom:                David Otto <ottodavid@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	elog
DISTVERSION=	2.6.3-1
CATEGORIES=	www
MASTER_SITES=	http://midas.psi.ch/elog/download/tar/

MAINTAINER=	ottodavid@gmx.net
COMMENT=	A fast and lightweight, extremly customizable weblog

MAN1=		elog.1 elconv.1
MAN8=		elogd.8
USE_RC_SUBR=	elogd
SUB_FILES=		pkg-install pkg-deinstall
SUB_LIST=		LOGBOOKDIR=${LOGBOOKDIR}

LOGBOOKDIR?=	www/elog
PLIST_SUB+=	LOGBOOKDIR=${LOGBOOKDIR}

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/elog-2.6.3
MAKE_ENV=	LOGBOOKDIR=${LOGBOOKDIR}

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "You may change the data directory with the option LOGBOOKDIR"
	@${ECHO_MSG} "Set NOPORTDOCS if you do not need any documentation"
	@${ECHO_MSG}

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN}  ${WRKSRC}/doc/* ${DOCSDIR}
.endif

	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
