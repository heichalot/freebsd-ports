# New ports collection makefile for:	german/vtiger
# Date created:				22 September  2007
# Whom:					Aron Schlesinger <as@bsdgroup.de>
#
# $FreeBSD$

PORTNAME=	vtiger
DISTVERSION=	5.0.3-ga-release-fix-1
PORTREVISION=	2
CATEGORIES=	german www
MASTER_SITES=	http://forge.vtiger.com/frs/download.php/322/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/vtiger/
PKGNAMEPREFIX=	de-
DISTNAME=	de_de.lang

MAINTAINER=	as@bsdgroup.de
COMMENT=	German messages for vtiger

WRKSRC=		${WRKDIR}/German_de_de
WWWDIR?=	${PREFIX}/www/${PORTNAME}

RUN_DEPENDS+=	${WWWDIR}/include/language:${PORTSDIR}/www/vtiger

NO_BUILD=	YES
USE_ZIP=	YES

SUB_FILES=	pkg-message

do-install:
	@${FIND} ${WRKSRC} -type f -exec ${SH} -c '${INSTALL_DATA} -v {} \
	$$(${ECHO} {} | ${SED} -e "s,^${WRKSRC},${WWWDIR},")' \;

post-install:
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC} -type f | ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}

.include <bsd.port.mk>
