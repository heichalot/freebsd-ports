# New ports collection makefile for:    LinNeighborhood
# Date created:                         2003/04/06
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	LinNeighborhood
PORTVERSION=	0.6.5
PORTREVISION=	10
CATEGORIES=	net
MASTER_SITES=	http://www.bnro.de/~schmidjo/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ gui for browsing and mounting SMB filesystems

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba3

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"\
		CC="${CC} -I${LOCALBASE}/include"
#                             ^
# this was done intentionaly in order to make `configure' pick up libintl.h

.include <bsd.port.pre.mk>

post-patch:
	${CP} ${FILESDIR}/mntent* ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
