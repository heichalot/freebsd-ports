# New ports collection makefile for: comiccron
# Date created:        9 March 2007
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	roxbg
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	x11 deskutils
MASTER_SITES=	http://vvelox.net/programs/unix/x11/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A tool for setting the background in rox using a simple command.

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/roxbg

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

#nothing to configure
do-configure:
	@${ECHO} -n

#nothing to make
do-build:
	@${ECHO} -n

do-install:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/roxbg
	@${CHMOD} +x ${PREFIX}/bin/roxbg

.include <bsd.port.mk>
