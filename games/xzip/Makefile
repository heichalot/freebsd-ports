# New ports collection makefile for:	xzip
# Date created:				28 June 1998
# Whom:					Matthew Hunt <mph@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xzip
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/infocom/interpreters/zip/ \
	ftp://www.plover.net/if-archive/infocom/interpreters/zip/ \
	ftp://ftp.guetech.org/if-archive/infocom/interpreters/zip/ \
	ftp://mirror.holmoak.co.uk/if-archive/infocom/interpreters/zip/ \
	ftp://ftp.funet.fi/pub/misc/if-archive/infocom/interpreters/zip/ \
	ftp://wuarchive.wustl.edu/doc/misc/if-archive/infocom/interpreters/zip/
DISTNAME=	xzip182
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An Infocom game interpreter that runs under X11

WRKSRC=		${WRKDIR}/xzip
ALL_TARGET=

USE_XORG=	x11

MAN1=		xzip.1
PLIST_FILES=	bin/xzip

.include <bsd.port.mk>
