# New ports collection makefile for:	eclipse-sysdeo-tomcat
# Date created:				July 29, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sysdeo
PORTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	java
MASTER_SITES=	http://www.sysdeo.com/sysdeo/content/download/393/4930/file/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-tomcat
DISTNAME=	tomcatPluginV31
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	Sysdeo Tomcat Launcher plugin for Eclipse

RUN_DEPENDS+=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} -p ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/com.sysdeo.eclipse.tomcat_${PORTVERSION} ${PREFIX}/eclipse/plugins
		@(cd ${WRKSRC}; ${FIND} -s com.sysdeo.eclipse.tomcat_${PORTVERSION} -not -type d) \
			| ${SED} -ne 's,^,eclipse/plugins/,p' >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d com.sysdeo.eclipse.tomcat_${PORTVERSION} -type d) \
			| ${SED} -ne 's,^,@dirrm eclipse/plugins/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
