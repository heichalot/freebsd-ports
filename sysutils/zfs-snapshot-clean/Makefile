# New ports collection makefile for:	zfs-snapshot-clean
# Date created:		2 January 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	zfs-snapshot-clean
PORTVERSION=	0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://download.github.com/ \
		ftp://ftp.iDaemons.org/pub/distfiles/
DISTNAME=	knu-${PORTNAME}-v${PORTVERSION}-0-g${FILEHASH}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A tool to sieve ZFS snapshots as per given spec a la 'pdumpfs-clean'

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/knu-${PORTNAME}-${FILEHASH}
PLIST_FILES=	sbin/${PORTNAME}

FILEHASH=	10b2b34

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/

.include <bsd.port.mk>
