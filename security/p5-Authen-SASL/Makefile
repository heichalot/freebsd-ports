# New ports collection makefile for:	p5-Authen-SASL
# Date created:				January 3rd 2003
# Whom:	      				Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-SASL
PORTVERSION=	2.14.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for SASL authentication

RUN_DEPENDS=	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC

OPTIONS=	KERBEROS "Enable Kerberos support" On

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	AUTOMATED_TESTING=yes

MAN3+=	Authen::SASL.3
MAN3+=	Authen::SASL::Perl.3
MAN3+=	Authen::SASL::Perl::ANONYMOUS.3
MAN3+=	Authen::SASL::Perl::CRAM_MD5.3
MAN3+=	Authen::SASL::Perl::DIGEST_MD5.3
MAN3+=	Authen::SASL::Perl::EXTERNAL.3
MAN3+=	Authen::SASL::Perl::GSSAPI.3
MAN3+=	Authen::SASL::Perl::LOGIN.3
MAN3+=	Authen::SASL::Perl::PLAIN.3

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_KERBEROS)
RUN_DEPENDS+=	p5-GSSAPI>0:${PORTSDIR}/security/p5-GSSAPI
.endif

.include <bsd.port.post.mk>
