# New ports collection makefile for:    jedit-devel
# Date created:				02 Feb 2004
# Whom:					Linh Pham <question+fbsdports@closedsrc.org>
#
# $FreeBSD$
#

PORTNAME=	jedit
DISTVERSION=	4.3.p18
CATEGORIES=	editors java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/4.3pre18
DISTNAME=	${PORTNAME}${PORTVERSION:S/.p/pre/}install
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	question+fbsdports@closedsrc.org
COMMENT=	Powerful programmer\'s text editor written in Java

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.5+

CONFLICTS=	jedit-4.2*
NO_LATEST_LINK=	yes

USE_XORG=	x11
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	jedit.sh

MAN1=		jedit.1
# The complete PLIST is generated in post-install
PLIST_FILES=	bin/jedit

do-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}| ; s|%%DATADIR%%|${DATADIR}| ; s|%%WRKDIR%%|${WRKDIR}|" ${FILESDIR}/instscript | \
		${SETENV} CLASSPATH=${DISTDIR}/${DISTNAME}.jar \
		${JAVA} installer.Install text
	@${INSTALL_SCRIPT} ${WRKDIR}/jedit.sh ${PREFIX}/bin/jedit

post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
