# New ports collection makefile for:	devel/p5-P4-Client
# Date created:				02 Sep 2003
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	P4-Client
PORTVERSION=	2.4319
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	P4::Client - Perl extension for the Perforce API

BUILD_DEPENDS=	${LOCALBASE}/lib/perforce/libclient.a:${PORTSDIR}/devel/p4api

BROKEN=		does not compile
DEPRECATED=	has been broken for 11 months
EXPIRATION_DATE=2010-01-08

PERL_CONFIGURE=	yes
CC=	${CXX}

MAN3=		P4::Client.3 P4::UI.3

post-patch:
	${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
