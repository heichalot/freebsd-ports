# New ports collection makefile for:	Math-SymbolicX-BigNum
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-BigNum
PORTVERSION=	0.02
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Big number support for the Math::Symbolic parser

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic \
		${SITE_PERL}/Math/SymbolicX/ParserExtensionFactory.pm:${PORTSDIR}/math/p5-Math-SymbolicX-ParserExtensionFactory
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::SymbolicX::BigNum.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
