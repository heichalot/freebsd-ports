# New ports collection makefile for:	p5-Unicode-String
# Date created:				10th September 2000
# Whom:					Ilia Chipitsine <ilia@jane.cgu.chel.su>
#
# $FreeBSD$
#

PORTNAME=	Unicode-String
PORTVERSION=	2.09
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	These are experimental Perl5 modules to handle various Unicode issues

PERL_CONFIGURE=	5.7.2+

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500804
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif

MAN3=		Unicode::CharName.3 Unicode::String.3

.include <bsd.port.post.mk>
