# New ports collection makefile for:	gemrb
# Date created:			21 Apr 2008
# Whom:				Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	gemrb
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	games emulators
MASTER_SITES=	SF/${PORTNAME}/GemRB%20Sources/GemRB%20${PORTVERSION}%20Sources

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	GemRB (Game engine made with preRendered Background)

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	-libdir=${LOCALBASE}/lib \
			-includedir=${LOCALBASE}/include

USE_GMAKE=	yes
USE_SDL=	sdl
USE_OPENAL=	al alut
USE_LDCONFIG=	yes
USE_PYTHON=	2.4+

MAN6=	gemrb.6

post-patch:
.if defined(NOPORTDOCS)
# TODO: Yep I know this is a ugly way ;/
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-*
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/gemrb.cfg ]; then \
		${CP} ${PREFIX}/etc/GemRB.cfg.sample ${PREFIX}/etc/gemrb.cfg; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
