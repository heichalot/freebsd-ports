# New ports collection makefile for:	mail/p5-Email-Reply
# Date created:				21 February 2007
# Whom:					Kay Abendroth <kay.abendroth@raxion.net>
#
# $FreeBSD$
#

PORTNAME=	Email-Reply
PORTVERSION=	1.202
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kay.abendroth@raxion.net
COMMENT=	Email::Reply - Reply to a Message

RUN_DEPENDS=	p5-Email-Abstract>=2.01:${PORTSDIR}/mail/p5-Email-Abstract \
		p5-Email-Address>=1.80:${PORTSDIR}/mail/p5-Email-Address \
		p5-Email-MIME>=1.82:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Simple>=2.100:${PORTSDIR}/mail/p5-Email-Simple

PERL_CONFIGURE=	5.8.1+

MAN3=	Email::Reply.3

.include <bsd.port.mk>
