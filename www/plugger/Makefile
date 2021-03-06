# New ports collection makefile for:	plugger
# Date created:		11 Februrary 1999
# Whom:			Jay Sachs <sachs@cs.williams.edu>
#
# $FreeBSD$
#

PORTNAME=	plugger
PORTVERSION=	5.1.3
PORTREVISION=	7
CATEGORIES=	www audio graphics multimedia
MASTER_SITES=	http://fredrik.hubbe.net/plugger/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multimedia front-end plugin for Mozilla or Opera

USE_XORG=	xext xt sm ice xext x11
GNU_CONFIGURE=	yes

MAN7=		plugger.7
PKGDEINSTALL=	${PKGINSTALL}

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=npplugger.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

post-patch:
	@${REINPLACE_CMD} -e \
	's|/usr/X11R6/lib/xscreensaver|${LOCALBASE}/bin/xscreensaver-hacks|g ; \
	s|+useFrontEndProgram||g' \
		${WRKSRC}/pluggerrc

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger-${PORTVERSION} \
		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger-controller \
		${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/plugger-oohelper \
		${PREFIX}/bin
	@${MKDIR} ${WEBPLUGINS_DIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger.so \
		${WEBPLUGINS_DIR}/npplugger.so
	@if [ -f ${PREFIX}/etc/pluggerrc-${PORTVERSION} ]; then \
		${MV} ${PREFIX}/etc/pluggerrc-${PORTVERSION} \
			${PREFIX}/etc/pluggerrc-${PORTVERSION}.old; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/pluggerrc \
		${PREFIX}/etc/pluggerrc-${PORTVERSION}.sample
	@${INSTALL_MAN} ${WRKSRC}/plugger.7 ${MANPREFIX}/man/man7

local-install:
	@${MKDIR} ${HOME}/.plugger
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger-${PORTVERSION} \
		${HOME}/.plugger
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger-controller \
		${HOME}/.plugger
	@${INSTALL_SCRIPT} ${WRKSRC}/plugger-oohelper \
		${HOME}/.plugger
	@if [ -f ${HOME}/.plugger/pluggerrc-${PORTVERSION} ]; then \
		${MV} ${HOME}/.plugger/pluggerrc-${PORTVERSION} \
			${HOME}/.plugger/pluggerrc-${PORTVERSION}.old; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/pluggerrc \
		${HOME}/.plugger/pluggerrc-${PORTVERSION}

local-mozilla-install: local-install
	@${MKDIR} ${HOME}/.mozilla/plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger.so \
		${HOME}/.mozilla/plugins/npplugger.so

local-opera-install: local-install
	@${MKDIR} ${HOME}/.opera/plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/plugger.so \
		${HOME}/.opera/plugins/npplugger.so

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
