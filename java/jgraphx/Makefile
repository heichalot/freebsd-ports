# Ports collection Makefile for:	jgraphx
# Date created:				5 Jan 2010
# Whom:					Chris Rees
#
# $FreeBSD$
#

PORTNAME=	jgraphx
PORTVERSION=	1.3.0.0
CATEGORIES=	java graphics
MASTER_SITES=	http://www.jgraph.com/downloads/jgraphx/archive/ \
		http://www.bayofrum.net/dist/jgraphx/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\./_/g}

MAINTAINER=	utisoft@gmail.com
COMMENT=	The Java Graph Diagram Component version X (jgraph v6+)

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_RUN=	yes

.if !defined(WITHOUT_COMPILE) || !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${ANT_CMD}:${PORTSDIR}/devel/apache-ant
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}
.endif

.if !defined(WITHOUT_COMPILE)
JAVA_BUILD=	yes
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

do-build:
.if !defined(WITHOUT_COMPILE) || !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGETS}
.endif

do-install: do-install-jar do-install-javadoc

do-install-jar:
	@${ECHO_CMD} -n  ">> Installing .jar file..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_CMD} " [DONE]"

do-install-javadoc:
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_CMD} " [DONE]"
.endif

.include <bsd.port.mk>
