# New ports collection makefile for:	hedgewars
# Date created:		24 May 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hedgewars
PORTVERSION=	0.9.13
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/hedgewars/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Worms-like turn based strategy game

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	depends on fpc which is only available for i386

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_SDL=	sdl mixer image ttf net
USE_FPC=	opengl
USE_QT_VER=	4
USE_LUA=	5.1+
QT_COMPONENTS=	corelib gui moc_build network \
		qmake_build rcc_build svg xml \
		uic_build
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="Hedgewars" \
		"Worms-like turn based strategy game" \
		"${DATADIR}/Data/Forts/FlowerhogL.png" \
		"hedgewars" \
		"Game;StrategyGame;" \
		false

post-patch:
	${ECHO} "include_directories(${LOCALBASE}/include)" >> \
		${WRKSRC}/QTfrontend/CMakeLists.txt

.include <bsd.port.mk>
