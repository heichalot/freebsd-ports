# New ports collection Makefile for: 	terminatorx
# Date created:			13 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/audio/terminatorx/Makefile,v 1.6 2007/08/04 03:51:28 marcus Exp $

PORTNAME=	terminatorx
PORTVERSION=	3.82
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://terminatorx.org/dist/
DISTNAME=	terminatorX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime audio synthesizer that allows you to "scratch" on audio data

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		rarian-sk-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile \
		lrdf.2:${PORTSDIR}/textproc/liblrdf \
		jack.0:${PORTSDIR}/audio/jack

USE_BZIP2=	yes
INSTALLS_OMF=	yes
USE_XORG=	x11 xext xi xxf86dga
USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-alsa \
		--disable-alsamidi
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN1=		terminatorX.1

OPTIONS=	MPG123 "mpg123 support" on \
		SOX "sox (.au) support" on \
		VORBIS "OGG Vorbis support" on \
		MAD "MPEG Audio Decoder (libmad) support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MPG123)
BUILD_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.else
CONFIGURE_ARGS+=	--disable-mpg123
.endif

.if !defined(WITHOUT_SOX)
BUILD_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.else
CONFIGURE_ARGS+=	--disable-sox
.endif

.if !defined(WITHOUT_VORBIS)
BUILD_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif

.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/mad
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${GREP} -lR "%%LOCALBASE%%" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g'
.if ${OSVERSION} <= 800501
	${REINPLACE_CMD} -e "s,only(struct dirent,only(const struct dirent," \
		${WRKSRC}/src/tX_dialog.cc
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/terminatorX ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/terminatorX.1 ${MANPREFIX}/man/man1
.for file in terminatorX-app.png terminatorX-mime.png
	${INSTALL_DATA} ${WRKSRC}/gnome-support/${file} \
		${PREFIX}/share/pixmaps
.endfor
.for file in terminatorX.mime terminatorX.keys
	${INSTALL_DATA} ${WRKSRC}/gnome-support/${file} \
		${PREFIX}/share/mime-info
.endfor
	${INSTALL_DATA} ${WRKSRC}/gnome-support/terminatorX.desktop \
		${PREFIX}/share/gnome/apps/Multimedia
	@${MKDIR} ${PREFIX}/share/gnome/help/terminatorX/C
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/terminatorX-manual.xml \
		${PREFIX}/share/gnome/help/terminatorX/C/terminatorX.xml
	@${MKDIR} ${PREFIX}/share/gnome/help/terminatorX/C/figures
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/figures/signalflow.png \
		${PREFIX}/share/gnome/help/terminatorX/C/figures
	@${MKDIR} ${PREFIX}/share/omf/terminatorX
	${INSTALL_DATA} ${WRKSRC}/doc/terminatorX-manual/C/terminatorX-manual-C.omf \
		${PREFIX}/share/omf/terminatorX/terminatorX-C.omf
	@scrollkeeper-install -q ${PREFIX}/share/omf/terminatorX/terminatorX-C.omf 2>/dev/null || ${TRUE}

.include <bsd.port.post.mk>
