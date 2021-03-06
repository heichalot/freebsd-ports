# New ports collection makefile for:	pawm
# Date created:				2002-08-22
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pawm
PORTVERSION=	2.2.9
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.pleyades.net/pawm/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Puto Amo Window Manager

USE_BZIP2=	yes
USE_XORG=	x11 xrandr xrender xpm
USE_GMAKE=	yes
MAKEFILE=	Makefile.in
MAKE_ARGS=	GCC="${CC}" MAKE.binary="${CC} ${LDFLAGS} -o"

CFLAGS+=	-I. -I${LOCALBASE}/include -DNDEBUG
LDFLAGS=	-lm -L${LOCALBASE}/lib -lXpm

.include <bsd.port.pre.mk>

LDFLAGS+=	-lXrandr
.if defined(WITHOUT_XFT)
CFLAGS+=	-DDISABLE_XFT
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CFLAGS+=	`pkg-config --cflags xft`
LDFLAGS+=	`pkg-config --libs xft`
.endif

.if defined(WITH_SN)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CFLAGS+=	-DENABLE_STARTUP -DSN_API_NOT_YET_FROZEN \
		`pkg-config --cflags libstartup-notification-1.0`
LDFLAGS+=	`pkg-config --libs libstartup-notification-1.0`
.endif

do-configure:
	@${ECHO_CMD} -n > ${WRKSRC}/config.h
	@${ECHO_CMD} '#define PROJECT "${PORTNAME}"' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define VERSION "${PORTVERSION}"' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define CONFDIR "${PREFIX}/etc"' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define DATADIR "${DATADIR}"' >> ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pawm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/conf/pawm.conf ${PREFIX}/etc
	@${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/data/icons/*.xpm ${DATADIR}/icons
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ii in AUTHORS Changelog GPL INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
