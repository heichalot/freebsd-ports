# New ports collection makefile for:	grails
# Date created:			2008-03-10
# Whom:				Mitchell Smith <mjs@bur.st>
#
# $FreeBSD$
#

PORTNAME=	grails
DISTVERSION=	1.2.2
CATEGORIES=	www java
MASTER_SITES=	http://dist.codehaus.org/grails/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mjs@bur.st
COMMENT=	Web framework built on Groovy

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:U}

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	LICENSE README build.properties build.xml ant conf cruise \
		dist lib media plugins samples scripts src
SCRIPTFILES=	grails grails-debug startGrails

.if !defined(NOPORTDOCS)
PORTDOCS=	api guide index.html css img ref
.endif
PLIST_FILES=	${SCRIPTFILES:S,^,bin/,} \
		${SCRIPTFILES:S,^,${DATADIR:S,${PREFIX}/,,}/bin/,}
PLIST_DIRS=	${DATADIR:S,${PREFIX}/,,}/bin
SUB_FILES=	edit-startGrails.sed pkg-message

do-install:
	@${ECHO_MSG} -n ">> Installing data files in ${DATADIR}..."
	@cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing and symlinking executables..."
	@${MKDIR} ${DATADIR}/bin
	@${REINPLACE_CMD} -f ${WRKDIR}/edit-startGrails.sed ${WRKSRC}/bin/startGrails
.for file in ${SCRIPTFILES}
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${DATADIR}/bin/${file}
	@${LN} -fs ${DATADIR}/bin/${file} ${PREFIX}/bin/${file}
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
