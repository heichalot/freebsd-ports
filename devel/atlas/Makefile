# New ports collection makefile for:	Atlas
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	Atlas
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/OldFiles
DISTNAME=	${PORTNAME}-C++-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A C++ reference implementation of the Atlas protocol

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	YES
USE_BZIP2=	YES
USE_GNOME=	gnomehack

post-patch:
	@${REINPLACE_CMD} -e 's| install-docDATA | |g'	${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS THANKS NEWS ChangeLog TODO HACKING ROADMAP
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
