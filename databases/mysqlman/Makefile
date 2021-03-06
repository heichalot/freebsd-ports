# New ports collection makefile for:    mysqlman
# Date created:         06.06.2002
# Whom: Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$

PORTNAME=	mysqlman
PORTVERSION=	1.09
PORTREVISION=	2
CATEGORIES=	databases www
MASTER_SITES=	http://www.gossamer-threads.com/scripts/source/
DISTNAME=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	MySQLMan is a web based MySQL database manager written in perl

RESTRICTED=	not redistributable, license agreement required

USE_PERL5=	yes
USE_APACHE=	1.3
USE_MYSQL=	yes

NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

#install dir of mysqlman
MYMANDIR=	www/mysqlman-${PORTVERSION}

#do the substitution according to the install place
PLIST_SUB+=	MYMANDIR=${MYMANDIR}

#FILES to patch
f="mysql.cgi"

#Web user
WEBUSER?=	${WWWOWN}:${WWWGRP}

.include <bsd.port.pre.mk>

do-configure:
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.bak && ${SED} <${WRKSRC}/${f}.bak \
		s+%%PATHPERLBIN%%+${PERL5}+g >${WRKSRC}/${f}

do-install:
	@${FIND} ${WRKSRC} ! \( -path "*/${f}*" -or -path "*/mysql.cfg" \) | ${XARGS} -n1 ${SH} -c 'if ${TEST} -d $$0; \
		then ${MKDIR} ${PREFIX}/${MYMANDIR}$${0#${WRKSRC}}; \
		else ${INSTALL_DATA} $$0 ${PREFIX}/${MYMANDIR}$${0#${WRKSRC}}; fi'
	@${INSTALL_SCRIPT} ${WRKSRC}/mysql.cgi ${PREFIX}/${MYMANDIR}
	@if [ -L ${PREFIX}/www/mysqlman ]; then \
		${ECHO} "Updating ${PREFIX}/www/mysqlman symbolic link" ; \
		${RM} ${PREFIX}/www/mysqlman ; \
	fi
	${LN} -s ${PREFIX}/${MYMANDIR} ${PREFIX}/www/mysqlman

post-install:
	@${CHOWN} ${WEBUSER} ${PREFIX}/${MYMANDIR}/templates/compiled
	@${INSTALL_DATA} ${WRKSRC}/mysql.cfg ${PREFIX}/${MYMANDIR}/mysql.cfg.dist
	@${ECHO} ""
	@${ECHO} "Sample config installed at \
			${PREFIX}/${MYMANDIR}/mysql.cfg.dist"
	@${ECHO} "Modify to your needs!"
	@${ECHO} ""

.include <bsd.port.post.mk>
