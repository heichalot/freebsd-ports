# New ports collection makefile for:	Math-SymbolicX-ParserExtensionFactory
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-ParserExtensionFactory
PORTVERSION=	3.02
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate parser extensions

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic
RUN_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic

MAN3=	Math::SymbolicX::ParserExtensionFactory.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
