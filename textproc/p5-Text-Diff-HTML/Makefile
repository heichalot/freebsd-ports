# New ports collection makefile for:	textproc/p5-Text-Diff-HTML
# Date created:				28 September 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Diff-HTML
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Text::Diff::HTML - XHTML format for Text::Diff::Unified

BUILD_DEPENDS=	${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Text::Diff::HTML.3

.include <bsd.port.mk>
