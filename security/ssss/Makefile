# New ports collection makefile for:	seccure
# Date created:				30 August 2007
# Whom:					Lukasz Komsta
#
# $FreeBSD$
#

PORTNAME=	ssss
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://point-at-infinity.org/ssss/

MAINTAINER=	luke@novum.am.lublin.pl
COMMENT=	Shamir's Secret Sharing Scheme

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

PLIST_FILES=	bin/ssss-combine bin/ssss-split

MAN1=		ssss.1

.include <bsd.port.mk>
