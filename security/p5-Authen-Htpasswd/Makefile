# New ports collection makefile for:	security/p5-Authen-Htpasswd
# Date created:				11 November 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Htpasswd
PORTVERSION=	0.161
CATEGORIES=	security perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Authen::Htpasswd - interface to read and modify Apache .htpasswd files
TAGS=		apache authentication pass password md5 sha1 crypto

BUILD_DEPENDS=	${SITE_PERL}/IO/LockedFile.pm:${PORTSDIR}/devel/p5-IO-LockedFile \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Crypt/PasswdMD5.pm:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Authen::Htpasswd.3 \
	Authen::Htpasswd::User.3 \
	Authen::Htpasswd::Util.3

.include <bsd.port.mk>
