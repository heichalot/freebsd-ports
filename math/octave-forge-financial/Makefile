# New ports collection makefile for:	octave-forge-financial
# Date created:		8 September 2008
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-financial
PORTVERSION=	0.3.2
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	stephen@missouri.edu
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
GNU_CONFIGURE=	yes

RUN_DEPENDS+=	${TARBALLS_DIR}/time.tar.gz:${PORTSDIR}/math/octave-forge-time
RUN_DEPENDS+=	${TARBALLS_DIR}/miscellaneous.tar.gz:${PORTSDIR}/math/octave-forge-miscellaneous

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"
.include <bsd.port.post.mk>
