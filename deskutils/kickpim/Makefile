# New ports collection makefile for:	kickpim
# Date created:			Mon Dec 29 16:29:43 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kickpim
PORTVERSION=		0.5.3
PORTREVISION=	10
CATEGORIES=		deskutils kde
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20_Society_

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Panel applet for editing and accessing the KDE addressbook

USE_KDEBASE_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:22
USE_LDCONFIG=		yes
CONFIGURE_ENV=		LDFLAGS="${PTHREAD_LIBS}"
MAKE_JOBS_UNSAFE=	yes

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
