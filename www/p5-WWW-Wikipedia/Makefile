# New ports collection makefile for:	p5-WWW-Wikipedia
# Date created:				Aug 5 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	WWW-Wikipedia
PORTVERSION=	1.9.4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module of Automated interface to the Wikipedia

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Text/Autoformat.pm:${PORTSDIR}/textproc/p5-Text-Autoformat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		wikipedia.1
MAN3=		WWW::Wikipedia.3 \
		WWW::Wikipedia::Entry.3

.include <bsd.port.mk>
