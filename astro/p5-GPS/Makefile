# New ports collection makefile for:	p5-GPS
# Date created:			5 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	GPS
PORTVERSION=	0.17
CATEGORIES=	astro perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-GPS-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl interface to GPS receivers

PERL_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN3=		GPS::Serial.3 \
		GPS::NMEA.3 \
		GPS::NMEA::Handler.3 \
		GPS::Garmin.3 \
		GPS::Garmin::Handler.3

.include <bsd.port.mk>
