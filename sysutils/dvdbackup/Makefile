# New ports collection makefile for:	dvdbackup
# Date created:		2004-09-24
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dvdbackup
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://dvd-create.sourceforge.net/ GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backup content from DVD to hard disk

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/dvdbackup
PORTDOCS=	README

do-build:
	${CC} -o ${WRKSRC}/dvdbackup ${CFLAGS} -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib -ldvdread ${WRKSRC}/src/dvdbackup.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dvdbackup ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
