# New ports collection makefile for:	wmtz
# Date created:			24 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmtz
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://www.geocities.com/jl1n/wmtz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays the time in different time zones

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" FLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBDIR="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${DISTNAME}/wmtz
USE_XORG=	xpm x11
MAN1=		wmtz.1
PLIST_FILES=	bin/wmtz \
		etc/wmtzrc.default

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmtz ${PREFIX}/bin/wmtz
	@${INSTALL_MAN} ${WRKSRC}/wmtz.1 ${PREFIX}/man/man1/
	@${ECHO} "===>   Installing wmtzrc.default in ${PREFIX}/etc."
	@${ECHO} "===>   Copy it to ~/.wmtzrc or ${PREFIX}/etc/wmtzrc and modify it."
	@${INSTALL_DATA} ${WRKSRC}/wmtzrc ${PREFIX}/etc/wmtzrc.default
	@${ECHO} "===>   Run wmtz --help for usage instructions"

.include <bsd.port.mk>
