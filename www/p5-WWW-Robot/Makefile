# New ports collection makefile for:	WWW-Robot
# Date created:				Wed Jan  3 08:06:35 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	WWW-Robot
PORTVERSION=	0.026
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	WWW::Robot - configurable web traversal engine

BUILD_DEPENDS=	${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/HTTP/Status.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset

PERL_CONFIGURE=	yes

MAN3=		WWW::Robot.3

.include <bsd.port.mk>
