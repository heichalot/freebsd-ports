# New ports collection makefile for:   weberp
# Date created:		05 Oct 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	weberp
PORTVERSION=	3.11.3
PORTREVISION=	1
CATEGORIES=	finance www
MASTER_SITES=	SF/web-erp/webERP/webERP_3.11
DISTNAME=	webERP_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An Open-Source Web-Based ERP System

USE_ZIP=	yes
USE_PHP=	mysql gettext
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}/webERP-temp

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}

	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
