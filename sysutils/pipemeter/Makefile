# New ports collection makefile for: 	pipemeter
# Date created:			2003-12-02
# Whom:				Len Sassama
#
# $FreeBSD$
#

PORTNAME=	pipemeter
PORTVERSION=	1.1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://ports.abditum.com/pipemeter/ \
		http://spamaps.org/files/pipemeter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for displaying pipe status information

GNU_CONFIGURE=	yes

MAN1=		pipemeter.1
PLIST_FILES=	bin/pipemeter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipemeter ${PREFIX}/bin/pipemeter
	${INSTALL_MAN} ${WRKSRC}/pipemeter.1 ${PREFIX}/man/man1/pipemeter.1

.include <bsd.port.mk>
