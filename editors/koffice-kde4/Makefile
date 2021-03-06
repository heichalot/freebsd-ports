# New ports collection makefile for:	koffice-kde4
# Date created:		2008-07-22
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	${KOFFICE2_VERSION}
PORTREVISION?=	0
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	-kde4
DIST_SUBDIR=	KDE/koffice

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Office suite for KDE

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2 \
		gmm++>=3.0.4:${PORTSDIR}/math/gmm++ \
		${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx30
LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		qca.2:${PORTSDIR}/devel/qca \
		GraphicsMagick++.1:${PORTSDIR}/graphics/GraphicsMagick \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		exiv2.7:${PORTSDIR}/graphics/exiv2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		kipi.7:${PORTSDIR}/graphics/kdegraphics4 \
		lcms.1:${PORTSDIR}/graphics/lcms \
		wpg-0.1:${PORTSDIR}/graphics/libwpg \
		png.6:${PORTSDIR}/graphics/png \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gsl.15:${PORTSDIR}/math/gsl \
		wv2.4:${PORTSDIR}/textproc/wv2 \
		freetype.9:${PORTSDIR}/print/freetype2 \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		fftw3.5:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx30

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_ICONV=	yes
USE_PGSQL=	yes
MAKE_JOBS_SAFE=	yes
USE_KDE4=	kdelibs pimlibs kdehier kdeprefix sharedmime automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib phonon qmake_build moc_build porting_build rcc_build uic_build \
		uic3_build
USE_GL=		glut glew
USE_LDCONFIG=	yes

CMAKE_OUTSOURCE=	yes

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include"

LDFLAGS+=	"-L${LOCALBASE}/lib"

OPTIONS+=	GTL	"Color transformations in Krita (broken with llvm-2.7)" off
OPTIONS+=	SYBASE	"SyBase support in Kexi" off
OPTIONS+=	XBASE	"XBase support in Kexi" off

.include <bsd.port.options.mk>

# GTL support is broken with llvm-2.7
WITHOUT_GTL=	yes

.if !defined(WITHOUT_GTL) || exists (${LOCALBASE}/lib/libQtShiva.so)
LIB_DEPENDS+=	OpenCTL.0:${PORTSDIR}/graphics/opengtl \
		QtShiva.0:${PORTSDIR}/graphics/qtgtl
PLIST_SUB+=	GTL=""
.else
PLIST_SUB+=	GTL="@comment "
.endif

.if exists(${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so)
BUILD_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
RUN_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
PLIST_SUB+=	EPS=""
.else
PLIST_SUB+=	EPS="@comment "
.endif

.if defined(WITH_SYBASE) || exists (${LOCALBASE}/lib/libsybdb.so)
LIB_DEPENDS+=	sybdb.5:${PORTSDIR}/databases/freetds
PLIST_SUB+=	SYBASE=""
.else
PLIST_SUB+=	SYBASE="@comment "
.endif

.if defined(WITH_XBASE) || exists (${LOCALBASE}/lib/libxbase-2.0.so)
LIB_DEPENDS+=	xbase-2.0.0:${PORTSDIR}/databases/xbase
PLIST_SUB+=	XBASE=""
.else
PLIST_SUB+=	XBASE="@comment "
.endif

post-patch:
# prevent updating mime during build/install
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${PATCH_WRKSRC}/krita/plugins/formats/ora/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindGLEW.cmake
	${REINPLACE_CMD} -e 's|/opt/local|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindImageMagick.cmake
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${PATCH_WRKSRC}/cmake/modules/FindWPD.cmake
	${REINPLACE_CMD} -e 's|-DHAVE_ICONV_H|-DHAVE_ICONV_H -L${LOCALBASE}/lib -liconv -Wl,-rpath -Wl,${LOCALBASE}/lib -liconv|' \
		${PATCH_WRKSRC}/filters/kword/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory(wv2)/d' \
		${PATCH_WRKSRC}/filters/kword/msword-odf/CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
