# New ports collection makefile for:	security/p5-Module-Signature
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Signature
PORTVERSION=	0.61
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Module signature file manipulation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA.pm:${PORTSDIR}/security/p5-Digest-SHA \
		${SITE_PERL}/PAR/Dist.pm:${PORTSDIR}/devel/p5-PAR-Dist \
		${LOCALBASE}/bin/gpgv:${PORTSDIR}/security/gnupg1
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		cpansign.1
MAN3=		Module::Signature.3

.include <bsd.port.mk>
