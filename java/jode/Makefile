# New ports collection makefile for:		jode-regexp
# Date created:					June 24th 2003
# Whom:						mi
#
# $FreeBSD$

PORTNAME=	jode
PORTVERSION=	1.1.1.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.1.2-pre1
DISTNAME=	${PORTNAME}-${VENDOR_VERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A java package containing a decompiler and an optimizer for java

BUILD_DEPENDS=	${GETOPT_JAR}:${PORTSDIR}/java/java-getopt
RUN_DEPENDS=	${BUILD_DEPENDS}

VENDOR_VERSION=	1.1.2-pre1
USE_JAVA=	yes
JAVA_VERSION=	1.2+
NEED_JAVAC=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

GETOPT_JAR=	${JAVALIBDIR}/getopt.jar
CLASSLIB=	${JAVA_CLASSES}:${GETOPT_JAR}
CONFIGURE_ENV+=	CLASSLIB=${CLASSLIB} JAR="${JAR}" \
		JAVA="${JAVA}" JAVAC="${JAVAC}"
CONFIGURE_ARGS+=--datadir="${JAVALIBDIR}"
# Don't create the dependencies:
MAKE_ARGS+=	JAVADEP=:
PLIST_SUB+=	VERSION=${VENDOR_VERSION}

post-patch:
	${FIND} ${WRKSRC} -name '*.java*' |	\
	    ${XARGS} ${GREP} --mmap -l 'Enumeration enum ' |	\
		${XARGS} ${REINPLACE_CMD} -E	\
			-e 's,enum([ \.]),enumeration\1,g'

post-build:
	cd ${WRKSRC} && ${JAR} cvf ${PORTNAME}-${VENDOR_VERSION}.jar \
		`${FIND} jode -name \*.class`

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${VENDOR_VERSION}.jar \
		${JAVAJARDIR}/
# Documentation HTML seems broken and out of date. Don't bother
#.ifndef (NOPORTDOCS)
#	${MKDIR} ${DOCSDIR}
#	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif ${DOCSDIR}/
#.endif

.include <bsd.port.mk>
