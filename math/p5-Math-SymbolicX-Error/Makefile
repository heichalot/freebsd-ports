# New ports collection makefile for:	Math-SymbolicX-Error
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-Error
PORTVERSION=	1.01
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parser extension for dealing with numeric errors

BUILD_DEPENDS=	${SITE_PERL}/Math/Symbolic.pm:${PORTSDIR}/math/p5-Math-Symbolic \
		${SITE_PERL}/Math/SymbolicX/ParserExtensionFactory.pm:${PORTSDIR}/math/p5-Math-SymbolicX-ParserExtensionFactory \
		${SITE_PERL}/Number/WithError.pm:${PORTSDIR}/math/p5-Number-WithError
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Math::SymbolicX::Error.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
