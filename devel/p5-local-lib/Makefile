# New ports collection makefile for:	local::lib
# Date created:		14 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	local-lib
PORTVERSION=	1.006000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MS/MSTROUT
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to create and use a local lib/ with PERL5LIB

RUN_DEPENDS=	\
	p5-ExtUtils-CBuilder>0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder \
	p5-Module-Build>=0.28:${PORTSDIR}/devel/p5-Module-Build \
	p5-ExtUtils-Install>=1.43:${PORTSDIR}/devel/p5-ExtUtils-Install
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	lib::core::only.3 \
	local::lib.3

.include <bsd.port.mk>
