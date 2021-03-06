# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	2.3.1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	datahead4@gmail.com
COMMENT=	Media player for KDE4

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		tag-extras.1:${PORTSDIR}/audio/taglib-extras \
		lastfm.0:${PORTSDIR}/audio/liblastfm \
		qca.2:${PORTSDIR}/devel/qca

BUILD_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so.1.0.0:${PORTSDIR}/devel/qtscriptgenerator
RUN_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so.1.0.0:${PORTSDIR}/devel/qtscriptgenerator

LATEST_LINK=	${PORTNAME}-kde4

MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network opengl script svg webkit \
		qmake_build moc_build rcc_build uic_build phonon
USE_GETTEXT=	yes
USE_MYSQL=	embedded
USE_CMAKE=	yes
USE_LDCONFIG=	yes

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	"GCC-related build error"

OPTIONS=	GPOD "iPod support" on \
		MTP "MTP device support" on \
		LOUDMOUTH "Loudmouth support" on

.include <bsd.port.options.mk>

.if defined(WITH_GPOD)
LIB_DEPENDS+=	gpod.5:${PORTSDIR}/audio/libgpod
PLIST_SUB+=	GPOD=""
.else
CMAKE_ARGS+=	-DWITH_Ipod:BOOL=Off
PLIST_SUB+=	GPOD="@comment "
.endif

.if defined(WITH_MTP)
LIB_DEPENDS+=	mtp.11:${PORTSDIR}/audio/libmtp
PLIST_SUB+=	MTP=""
.else
CMAKE_ARGS+=	-DWITH_Mtp:BOOL=Off
PLIST_SUB+=	MTP="@comment "
.endif

.if defined(WITH_LOUDMOUTH)
LIB_DEPENDS+=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth
PLIST_SUB+=	LOUDMOUTH=""
.else
CMAKE_ARGS+=	-DWITH_Loudmouth:BOOL=Off
PLIST_SUB+=	LOUDMOUTH="@comment "
.endif

.if ${OSVERSION} < 700000
CMAKE_USE_PTHREAD=	yes
.endif

post-extract:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/modules/FindMySQLAmarok.cmake
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/cmake/modules/FindIpod.cmake \
		${WRKSRC}/cmake/modules/FindLoudmouth.cmake \
		${WRKSRC}/cmake/modules/FindGdk.cmake

.include <bsd.port.mk>
