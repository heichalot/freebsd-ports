# New ports collection makefile for:	carthage
# Date created:				18 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	carthage
PORTVERSION=	1.0 # No version information on WWW
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Software/carthage/ \
		http://www.tei-c.org.uk/Software/carthage/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A parser and clean-up tool for SGML DTDs

USE_BISON=	build
USE_ZIP=	yes
USE_GMAKE=	yes
ALL_TARGET=	carthago

post-patch:
	${CHMOD} +w ${WRKSRC}/dpplex.c
	${REINPLACE_CMD} -e 's,make,$$(MAKE),' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/carthage ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/carthago ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/carthage
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/carthage
	@${INSTALL_MAN} ${WRKSRC}/README.SPQR ${PREFIX}/share/doc/carthage
.endif

.include <bsd.port.mk>
