# New ports collection makefile for:	URI-ParseSearchString
# Date created:	   19 Aug 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	URI-ParseSearchString
PORTVERSION=	3.41
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse Apache refferer logs and extract search engine query strings

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_CONFIGURE=	yes

MAN3=		URI::ParseSearchString.3

.include <bsd.port.mk>
