# New ports collection makefile for:	legesmotus
# Date created:		16 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	legesmotus
PORTVERSION=	0.3.0
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A team-based, networked, 2D shooter set in zero-gravity

USE_GMAKE=	yes
MAKE_ENV=	DATADIR=${DATADIR} XDIR=${LOCALBASE}
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

MAN6=		lmserver.6

OPTIONS=	LM_SERVER_ONLY "Build dedicated server only" off

DESKTOP_ENTRIES="Leges Motus" \
		"A team-based, networked, 2D shooter set in zero-gravity" \
		"${DATADIR}/sprites/blue_head32.png" \
		"legesmotus" \
		"Game;ActionGame;" \
		false

.include <bsd.port.options.mk>

.if defined(WITH_LM_SERVER_ONLY)
PLIST_SUB+=	CLIENT="@comment "
ALL_TARGET=	server
PKGNAMESUFFIX=	-server
.else
MAN6+=		legesmotus.6
PLIST_SUB+=	CLIENT=""
USE_SDL=	sdl image ttf mixer
USE_GL=		gl
.endif

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${DATADIR}
.if !defined(WITH_LM_SERVER_ONLY)
	${INSTALL_PROGRAM} ${WRKSRC}/client/legesmotus ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man6/legesmotus.6 ${MAN6PREFIX}/man/man6/
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} '*' ${DATADIR}/
.else
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} 'maps' ${DATADIR}/
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/server/lmserver ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man6/lmserver.6 ${MAN6PREFIX}/man/man6/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
