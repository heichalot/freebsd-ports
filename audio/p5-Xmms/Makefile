# New ports collection makefile for:	Xmms
# Date created:			10 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	Xmms
PORTVERSION=	0.12
PORTREVISION=	3
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-Perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive remote control shell for xmms

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		${site_perl}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${site_perl}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

site_perl=	${SITE_PERL}

PERL_CONFIGURE=	YES

MAN3=		Xmms::Remote.3 \
		Xmms::SongChange.3 \
		Xmms.3 \
		Bundle::Xmms.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500800
MAN3+=		Xmms::Config.3
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/SongChange/Makefile.PL

.include <bsd.port.post.mk>
