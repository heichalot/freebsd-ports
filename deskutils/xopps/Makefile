# New ports collection makefile for:	xopps
# Date created:		1 Ag 1997
# Whom:			Pedro Giffuni (orig)
#
# $FreeBSD$
#

PORTNAME=	xopps
PORTVERSION=	1.13
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://cvsup.theplanet.com/distfiles/ \
		http://dl.droso.net/ports/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool which lets you draw Gantt charts

ALL_TARGET=
USE_MOTIF=	yes
MAKE_ENV=	'MACH=${OPSYS}'

MAN1=	xopps.1

post-extract:
	@${CP} ${WRKSRC}/Defines.spr ${WRKSRC}/Defines.${OPSYS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/*.c

.include <bsd.port.mk>
