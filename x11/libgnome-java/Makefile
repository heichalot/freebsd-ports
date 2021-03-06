# New ports collection makefile for:   libgnome-java
# Date created:        28 February 2004
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/libgnome-java/Makefile,v 1.9 2005/10/29 22:06:06 marcus Exp $
#

PORTNAME=	libgnome-java
PORTVERSION=	2.12.7
PORTREVISION=	5
CATEGORIES=	x11 java
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Java wrapper for GNOME 2

BUILD_DEPENDS=	${JAVALIBDIR}/gtk${GTK_API_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java
RUN_DEPENDS=	${JAVALIBDIR}/gtk${GTK_API_VERSION}.jar:${PORTSDIR}/x11-toolkits/libgtk-java

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GNOME=	gnomehack libgnomeui
CONFIGURE_ARGS=	--without-gcj-compile --with-jardir=${JAVAJARDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd" \
		ac_cv_path_DB1="nocommand" \
		ac_cv_path_DB2="nocommand"
MAKE_JOBS_UNSAFE=	yes

# jikes related
CONFIGURE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}
MAKE_ENV+=	BOOTCLASSPATH=${JAVA_CLASSES}

GNOME_API_VERSION=	2.12
GTK_API_VERSION=	2.10
PLIST_SUB=		GNOME_API_VERSION=${GNOME_API_VERSION} PORTNAME=${PORTNAME}

PKGMESSAGE=		${WRKDIR}/pkg-message

post-extract:
	@${REINPLACE_CMD} -e 's|||g' \
		${WRKSRC}/gnome2-java.pc.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/.libs/libgnomejni-${GNOME_API_VERSION}.so \
		${PREFIX}/lib/libgnomejni-${GNOME_API_VERSION}.so.1
	${LN} -sf ${PREFIX}/lib/libgnomejni-${GNOME_API_VERSION}.so.1 \
		${PREFIX}/lib/libgnomejni-${GNOME_API_VERSION}.so
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/gnome2-java.pc	${PREFIX}/libdata/pkgconfig
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/gnome${GNOME_API_VERSION}.jar ${JAVAJARDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
	${MKDIR} ${PREFIX}/share/${PORTNAME}/tutorial
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial/* ${PREFIX}/share/${PORTNAME}/tutorial
	${MKDIR} ${DOCSDIR}/api
	cd ${WRKSRC}/doc/api && ${FIND} . | ${CPIO} -pdmu ${DOCSDIR}/api
	${TOUCH} ${DOCSDIR}/api/packages.html
	${MKDIR} ${DOCSDIR}/examples
	cd ${WRKSRC}/doc/examples && ${FIND} . \
		| ${CPIO} -pdmu ${DOCSDIR}/examples
.endif
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%GNOME_API_VERSION%%|${GNOME_API_VERSION}|g' \
		 < ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
