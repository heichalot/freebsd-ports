# New ports collection makefile for:	p5-Net-Domain-ExpireDate
# Date created:				Mar 4 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Net-Domain-ExpireDate
PORTVERSION=	0.97
CATEGORIES=	dns net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module obtain expiration date of domain names

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/Piece.pm:${PORTSDIR}/devel/p5-Time-Piece \
		${SITE_PERL}/Net/Whois/Raw.pm:${PORTSDIR}/net/p5-Net-Whois-Raw \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Domain::ExpireDate.3

post-patch:
		@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
