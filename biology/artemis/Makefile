# New ports collection makefile for:	artemis
# Date created:				10 Nov 2001
# Whom:					camson@bilateral.com.au
#
# $FreeBSD$
#

PORTNAME=	artemis
PORTVERSION=	9
PORTREVISION=	1
CATEGORIES=	biology java
MASTER_SITES=	http://www.sanger.ac.uk/Software/Artemis/v${PORTVERSION}/ \
		ftp://ftp.sanger.ac.uk/pub/pathogens/software/artemis/v${PORTVERSION}/
DISTNAME=	artemis_compiled_v${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A DNA sequence viewer and annotation tool

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.4+

NO_BUILD=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS -exec ${RM} -rf {} +

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}-${PORTVERSION}
	@${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${PREFIX}/${PORTNAME}-${PORTVERSION} -xpf-
	@${LN} -s ${PREFIX}/${PORTNAME}-${PORTVERSION}/art ${PREFIX}/bin/art
	@${LN} -s ${PREFIX}/${PORTNAME}-${PORTVERSION}/act ${PREFIX}/bin/act

.include <bsd.port.mk>
