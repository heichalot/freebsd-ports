# New ports collection makefile for:    fontmatrix
# Date created:         2008-01-13
# Whom:                 Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	fontmatrix
DISTVERSION=	0.4.2
DISTVERSIONSUFFIX=	-Source
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.fontmatrix.net/archives/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A graphical font manager

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_QT_VER=	4
QT_COMPONENTS=	gui svg network moc_build uic_build rcc_build qmake_build linguist_build
INSTALLS_ICONS=	yes

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

OPTIONS=	FONTFORGE "With FontForge editor" off

.include <bsd.port.pre.mk>

.if defined(WITH_FONTFORGE)
RUN_DEPENDS+=	${LOCALBASE}/bin/fontforge:${PORTSDIR}/print/fontforge
.endif

post-patch:
	cd ${WRKSRC}/src && \
		${REINPLACE_CMD} -e 's:/usr/bin/fontforge:${LOCALBASE}/bin/fontforge:g' \
		prefs_panel.ui \
		typotek.cpp

pre-configure:
	cd ${WRKSRC}/src/messages && \
		${LOCALBASE}/bin/lupdate-qt4 -noobsolete ../ -ts *.ts && \
		${LOCALBASE}/bin/lrelease-qt4 *.ts

.include <bsd.port.post.mk>
