# New ports collection makefile for:	www/p5-CGI-Prototype
# Date created:				20 April 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Prototype
PORTVERSION=	0.9053
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Create a CGI application by subclassing

BUILD_DEPENDS=	${SITE_PERL}/Class/Prototyped.pm:${PORTSDIR}/devel/p5-Class-Prototyped \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	CGI::Prototype.3 \
	CGI::Prototype::Hidden.3

.include <bsd.port.mk>
