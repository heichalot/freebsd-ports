# ex:ts=8
# Ports collection makefile for:	K.R.S.S.
# Date created:			Apr 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	krss
PORTVERSION=	2.6
PORTREVISION=	11
CATEGORIES=	deskutils kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE Rich Site Summary viewer

USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	LIBQT="-lqt-mt ${PTHREAD_LIBS}" KDB2HTML=${TRUE}
MAKE_ENV=	LIBQT="-lqt-mt ${PTHREAD_LIBS}" KDB2HTML=${TRUE}

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	${REINPLACE_CMD} -e 's|$$(LIB_KFILE)|-lkio|' ${WRKSRC}/krss/Makefile.in
	${REINPLACE_CMD} -e 's|-pedantic||;s|-Wmissing-prototypes||' \
		${WRKSRC}/configure

.include <bsd.port.mk>
