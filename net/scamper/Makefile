# New ports collection makefile for:  scamper
# Date created:        18 Mey 2005
# Whom:                dikshie
#
# $FreeBSD$
#

PORTNAME=	scamper
PORTVERSION=	20100517
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.wand.net.nz/scamper/
DISTNAME=	${PORTNAME}-cvs-${PORTVERSION}

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement

MAN1=		scamper.1

PLIST_FILES=	bin/scamper

post-install:
	${INSTALL_MAN} ${WRKSRC}/scamper.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
