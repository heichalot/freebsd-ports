# New ports collection makefile for:	textproc/p5-Text-Table
# Date created:				May  2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Table
PORTVERSION=	1.114
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Organize Data in Tables

BUILD_DEPENDS=	${SITE_PERL}/Text/Aligner.pm:${PORTSDIR}/textproc/p5-Text-Aligner
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Table.3

.include <bsd.port.mk>
