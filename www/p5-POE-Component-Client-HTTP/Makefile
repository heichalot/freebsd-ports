# New ports collection makefile for:	POE-Component-Client-HTTP
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-HTTP
PORTVERSION=	0.8200
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/00$//}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE component for non-blocking/concurrent HTTP queries

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/POE/Component/Client/Keepalive.pm:${PORTSDIR}/net/p5-POE-Component-Client-Keepalive
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Client::HTTP.3 \
		POE::Component::Client::HTTP::Request.3 \
		POE::Component::Client::HTTP::RequestFactory.3 \
		POE::Filter::HTTPChunk.3 POE::Filter::HTTPHead.3

.include <bsd.port.mk>
