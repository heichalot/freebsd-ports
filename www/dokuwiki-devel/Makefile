# New ports collection makefile for:	dokuwiki-devel
# Date created:		2006-06-09
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dokuwiki
PORTVERSION=	${DIST_VER:S/${PORTNAME}//:S/-//g}
CATEGORIES=	www
MASTER_SITES=	http://dev.splitbrain.org/download/snapshots/
PKGNAMESUFFIX=	-devel
DISTNAME=	${DIST_VER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple and easy to use wiki, no database required

WRKSRC=	${WRKDIR}/${PORTNAME}

DIST_VER=	${PORTNAME}-2009-09-22
USE_PHP=	gd mbstring pcre session xml zlib
NO_BUILD=	YES
WANT_PHP_WEB=	YES
CONFLICTS=	dokuwiki-[0-9]*

DOKUWIKI_DIR?=	www/${PORTNAME}
PLIST_SUB=	DOKUWIKI_DIR=${DOKUWIKI_DIR}
TEMP_PLIST=	${WRKDIR}/temp-pkg-plist

REINPLACE_ARGS=	-i ''

.include <bsd.port.pre.mk>

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|%%DOKUWIKI_DIR%%/|' > ${TEMP_PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm %%DOKUWIKI_DIR%%/|' >> ${TEMP_PLIST} \
		&& ${ECHO_CMD} "@dirrmtry %%DOKUWIKI_DIR%%" >> ${TEMP_PLIST}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/bin/*.php
	@${FIND} ${WRKSRC}/bin -name '*.orig' -delete

do-install:
# Data files
	-${MKDIR} ${PREFIX}/${DOKUWIKI_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${DOKUWIKI_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKI_DIR}

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%PORTNAME%%|${PORTNAME}|' \
		-e 's|%%DOKUWIKI_DIR%%|${DOKUWIKI_DIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
