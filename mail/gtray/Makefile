# New ports collection makefile for:	gtray
# Date created:		30 June 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	gtray
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	mail gnome
MASTER_SITES=	http://gnome-gtray.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tray applet that checks your GMail account status

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtktrayicon.so:${PORTSDIR}/x11/ruby-gtktrayicon \
		${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2

USE_RUBY=	yes
USE_GNOME=	gtk20
NO_BUILD=	yes

do-configure:
	cd ${WRKSRC} && ${SH} configure ${PREFIX}

.include <bsd.port.mk>
