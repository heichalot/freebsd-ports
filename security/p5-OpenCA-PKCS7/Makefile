# New ports collection makefile for:	OpenCA-PKCS7
# Date created:	   02 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	OpenCA-PKCS7
PORTVERSION=	0.9.13
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl extension for basic handling PKCS#7 Signatures

BUILD_DEPENDS=	${SITE_PERL}/X500/DN.pm:${PORTSDIR}/net/p5-X500-DN
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
