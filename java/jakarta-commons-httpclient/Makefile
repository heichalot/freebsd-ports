# Ports collection makefile for:	Jakarta Commons HttpCLient
# Date created:			17 October 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-httpclient
DISTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	java www
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	httpcomponents/${PORTNAME}/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A package implementing the client side of the HTTP standard

BUILD_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging
BUILD_DEPENDS+=	${JAVAJARDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec
RUN_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging
RUN_DEPENDS+=	${JAVAJARDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
ALL_TARGET=	dist

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	LICENSE api

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
