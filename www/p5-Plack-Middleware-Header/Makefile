# New ports collection makefile for:	Plack::Middleware::Header
# Date created:		02 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-Header
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to modify HTTP response headers

RUN_DEPENDS=	\
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Middleware::Header.3

.include <bsd.port.mk>
