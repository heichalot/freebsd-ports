# New ports collection makefile for:	p5-Audio-FLAC-Header
# Date created:		21 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Audio-FLAC-Header
PORTVERSION=	2.3
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Interface to FLAC header metadata

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac

PERL_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAN3=		Audio::FLAC::Header.3

.include <bsd.port.mk>
