# New ports collection makefile for:	HTTP-DAV
# Date created:	   02 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	HTTP-DAV
PORTVERSION=	0.40
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	WebDAV client library

BUILD_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		dave.1
MAN3=		HTTP::DAV.3 HTTP::DAV::Lock.3 HTTP::DAV::Resource.3 \
		HTTP::DAV::Response.3

.include <bsd.port.mk>
