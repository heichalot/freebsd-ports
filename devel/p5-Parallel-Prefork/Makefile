# New ports collection makefile for:	devel/p5-Parallel-Prefork
# Date created:				23 September 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Parallel-Prefork
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Parallel
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A simple prefork server framework

BUILD_DEPENDS=	p5-Proc-Wait3>=0.03:${PORTSDIR}/devel/p5-Proc-Wait3 \
		p5-Class-Accessor>=0.31:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Scope-Guard>=0:${PORTSDIR}/devel/p5-Scope-Guard

RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Parallel::Prefork.3 Parallel::Prefork::SpareWorkers.3

.include <bsd.port.mk>
