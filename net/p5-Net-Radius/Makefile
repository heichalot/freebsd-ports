# New ports collection makefile for:	p5-Net-Radius
# Date created:				20 Mar 2002
# Whom:                			Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Radius
PORTVERSION=	2.103
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl module to manipulate RADIUS packets

PERL_CONFIGURE=	yes
MAN3=		Net::Radius::Dictionary.3 Net::Radius::Packet.3

post-extract:
	${FIND} ${WRKDIR} -type f | ${XARGS} ${PERL5} -pi -e "s:\r::g"

.include <bsd.port.mk>
