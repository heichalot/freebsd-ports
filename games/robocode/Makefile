# New ports collection makefile for:    robocode
# Date created:				10 September 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	robocode
PORTVERSION=	1.7.1.6
CATEGORIES=	games java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-setup
EXTRACT_SUFX=	.jar

MAINTAINER=	glen.j.barber@gmail.com
COMMENT=	A game for learning Java[tm] programming language

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

INSTFILES=	battles javadoc license robocode.ico \
		libs robots templates versions.txt

SUB_FILES=	robocode.sh

do-install:
	@cd ${WRKSRC} && \
		${FIND} ${INSTFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	@cd ${WRKSRC} && \
		${FIND} ${INSTFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	@${INSTALL_SCRIPT} ${WRKDIR}/robocode.sh ${PREFIX}/bin/robocode

post-install:
	${MKDIR} -m a+rwx ${DATADIR}/compilers ${DATADIR}/config
	${CAT} pkg-message

.include <bsd.port.mk>
