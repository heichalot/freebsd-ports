# New ports collection makefile for:	scanssh
# Date created:		09 September 2000
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	scanssh
PORTVERSION=	2.1
PORTREVISION=	7
CATEGORIES=	security net
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Scans networks for open proxies, SSH, Web and SMTP servers

LIB_DEPENDS=	dnet:${PORTSDIR}/net/libdnet \
		event-1.4:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	YES
PLIST_FILES=	bin/scanssh

MAN1=		scanssh.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanssh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scanssh.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
