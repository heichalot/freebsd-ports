# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	qt3support
PORTVERSION=	${QT4_VERSION}
PORTREVISION=	1
CATEGORIES?=	devel x11-toolkits
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt3 compatibility library

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build corelib gui network sql xml
QT_NONSTANDARD=	yes
QT_DIST=	yes
MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/qt4
USE_XLIB=	yes

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/activeqt src/dbus src/multimedia src/opengl src/openvg \
		src/phonon src/s60installs src/s60main src/script \
		src/scripttools src/svg src/testlib src/tools src/winmain \
		src/xmlpatterns src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff src/3rdparty/phonon src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

EXTRA_PATCHES=	${.CURDIR}/../../devel/qt4/files/patch-configure

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/bin/moc
post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' ${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
		${WRKSRC}/lib/pkgconfig/Qt3Support.pc

.include <bsd.port.mk>
