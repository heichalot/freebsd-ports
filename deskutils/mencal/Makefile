# New ports collection makefile for:    mencal
# Date created:                 17 April 2002
# Whom:                         Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	mencal
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://kyberdigi.cz/projects/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A variation of the unix command cal

USE_PERL5=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/mencal

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL} -w|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mencal ${PREFIX}/bin

.include <bsd.port.mk>
