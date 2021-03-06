# ex:ts=8
# New ports collection makefile for:	rascal
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rascal
PORTVERSION=	0.3.2
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/Rascal/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Advanced Scientific CALculator

WRKSRC=		${WRKDIR}/Rascal-${PORTVERSION}

USE_BISON=	build
WANT_GNOME=	yes
USE_GMAKE=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	${PROGRAMS}

MAN1=	rascal.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.else
BROKEN=		does not link
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomelibs
PROGRAMS=	rascal grascal
.else
PROGRAMS=	rascal
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CC=|CC?=|g ; \
		 s|^CFLAGS=-|CFLAGS+=$${CPPFLAGS} -|g ; \
		 s|-O0 -fno-rtti -g||g ; \
		 s|^LIBS=-|LIBS+=$${LDFLAGS} -|g ; \
		 s|doc/|share/doc/|g ; \
		 s|g++|$${CC}|g ; \
		 s|-Os||g ; \
		 s|gnome-config|$${GNOME_CONFIG}|g' ${WRKSRC}/Makefile
.for file in hoc.y rascal.1 grascal.cpp
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${file}
.endfor

do-install:
.for file in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/rascal.rc ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/rascal.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
.for file in rascal.ps rascal.pdf CHANGES TEST TOOLBOXTEST
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/rascal_html/* ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
