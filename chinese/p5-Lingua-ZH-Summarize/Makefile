# ex:ts=8
# Ports collection makefile for:	p5-Lingua-ZH-Summarize
# Date Created:			Oct 10, 2003
# Whom:				clsung
#
# $FreeBSD$

PORTNAME=	Lingua-ZH-Summarize
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese Text Summarization

BUILD_DEPENDS=	${SITE_PERL}/Lingua/ZH/Toke.pm:${PORTSDIR}/chinese/p5-Lingua-ZH-Toke \
		${SITE_PERL}/Lingua/ZH/Wrap.pm:${PORTSDIR}/chinese/p5-Lingua-ZH-Wrap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::ZH::Summarize.3

.include <bsd.port.mk>
