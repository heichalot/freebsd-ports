# New ports collection makefile for:	app_notify
# Date created:				23 March 2007
# Whom:					mayo
#
# $FreeBSD$
#

PORTNAME=	app_notify
DISTVERSION=	2.0rc1
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://www.mezzo.net/asterisk/ \
		http://static.oyam.ca/freebsd/ports/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mayo@oyam.ca
COMMENT=	Notify application module for the Asterisk PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

USE_GMAKE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
