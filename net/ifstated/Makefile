# New ports collection makefile for: ifstated
# Date created:         18 November 2004
# Whom:                 Matthew George <mdg@secureworks.net>
#
# $FreeBSD$
#

PORTNAME=	ifstated
PORTVERSION=	3.7
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://www.atarininja.org/~wxs/distfiles/ \
		http://www.pkix.net/mirror/f2o.org/ifstated/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Interface State daemon

INSTALL_TARGET=	install install-man
MAN8=		ifstated.8

PLIST_FILES=	sbin/ifstated etc/ifstated.conf
SUB_FILES=	pkg-message

USE_RC_SUBR=	ifstated

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ifstated.c ${WRKSRC}/ifstated.8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
