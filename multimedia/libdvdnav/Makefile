# New ports collection makefile for:    libdvdnav
# Date created:         21 May 2002
# Whom:                 MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	libdvdnav
PORTVERSION=	0.1.10
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF/dvd/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	The library for the xine-dvdnav plugin

CONFLICTS=	libdvdnav-mplayer-[0-9]*

CONFIGURE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-transform-name=''
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22 autoconf:262 automake:16

# Internal libdvdread staticly dlopens libdvdcss.so.2
DVDCSS_LIBVERSION=	3

post-patch:
	${REINPLACE_CMD} -e \
		's|THREAD_LIBS="[^"]*"$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib|-L${LOCALBASE}/lib|g ; \
		 s|-I/usr/local/include|-I${LOCALBASE}/include|g' \
		 ${WRKSRC}/configure ${WRKSRC}/configure.ac \
		 ${WRKSRC}/missing ${WRKSRC}/aclocal.m4 ${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -E -e 's|(libdvdcss.so)\.2|\1.${DVDCSS_LIBVERSION}|' \
		${WRKSRC}/src/dvdread/dvd_input.c

post-configure:
	${REINPLACE_CMD} -e 's|automake[0-9][0-9]|${TRUE}|' \
		`${FIND} ${WRKSRC} -type f -name Makefile`

.include <bsd.port.mk>
