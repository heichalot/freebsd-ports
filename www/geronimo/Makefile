# New ports collection makefile for:	geronimo
# Date created:		26 Apr 2007
# Whom:			Nemo Liu <nemoliu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geronimo
PORTVERSION=	2.2
CATEGORIES=	www devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	geronimo/${PORTVERSION}
DISTNAME=	${PORTNAME}-${WEBSERVER}-javaee5-${PORTVERSION}-bin

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Open-source Java EE 5 application server

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	YES

USE_RC_SUBR=	geronimo2.sh
SUB_FILES=	pkg-install pkg-deinstall

OPTIONS=	TOMCAT6 "Use Tomcat instead of default Jetty" off

.include <bsd.port.pre.mk>

.if defined(WITH_TOMCAT6)
WEBSERVER=	tomcat6
.else
WEBSERVER=	jetty7
.endif

MAJOR_VER=	${PORTVERSION:C/\..*//}
APP_HOME?=	${PREFIX}/${PKGBASE}${MAJOR_VER}
LOG_DIR=	${APP_HOME}/var/log
APP_TITLE=	Geronimo
APP_SHORTNAME=	geronimo${MAJOR_VER}
GERONIMO_USER?=	www
GERONIMO_GROUP?=www
GERONIMO_OUT=	${LOG_DIR}/geronimo.out
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=		${WRKDIR}/${DISTNAME:S/-bin//}
JAR_FILE=	bin/server.jar
LATEST_LINK=	${APP_SHORTNAME}
PLIST_FILES=	${GERONIMO_OUT:S,^${PREFIX}/,,}

SUB_LIST=	GERONIMO_HOME=${APP_HOME} \
		APP_SHORTNAME=${APP_SHORTNAME} \
		APP_TITLE="${APP_TITLE}" \
		GROUP=${GERONIMO_GROUP} \
		HTTP_PORT=${HTTP_PORT} \
		JAR_FILE=${JAR_FILE} \
		PID_FILE=${PID_FILE} \
		GERONIMO_OUT=${GERONIMO_OUT} \
		USER=${GERONIMO_USER} \
		GERONIMO_VERSION=${MAJOR_VER} \
		GERONIMO_OUT=${GERONIMO_OUT} \
		JAVA_HOME=${JAVA_HOME}

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG} "   Running as (user/group):  ${GERONIMO_USER}/${GERONIMO_GROUP}"
	@${ECHO_MSG} "   Logfile:		   ${GERONIMO_OUT}"

post-patch:
	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${RM} -f `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_MSG} " [ DONE ]"

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${APP_HOME} && ${CHOWN} ${GERONIMO_USER}:${GERONIMO_GROUP} ${APP_HOME}
	@(cd ${WRKSRC} && ${FIND} . |\
		 ${CPIO} -pdmu -R ${GERONIMO_USER}:${GERONIMO_GROUP} ${APP_HOME})
	${INSTALL} -o ${GERONIMO_USER} -g ${GERONIMO_GROUP} -m 0644 /dev/null ${GERONIMO_OUT}
post-install:
	@${ECHO_MSG} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
	@${FIND} -s ${WRKSRC} -not -type d | \
		 ${SED} -ne 's,^${WRKSRC},${APP_HOME:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type d | \
		 ${SED} -ne 's,^${WRKSRC},@dirrm ${APP_HOME:S,${PREFIX}/,,},p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
