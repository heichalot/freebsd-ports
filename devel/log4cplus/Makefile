# New ports collection makefile for:	log4cplus
# Date created:				16 November 2004
# Whom:					Petri Totterman <petri.totterman@hmv.fi>
#
# $FreeBSD$
#

PORTNAME=	log4cplus
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}
DISTFILES=	log4cplus-${PORTVERSION}.tar.gz log4cplus-${PORTVERSION}-docs.tar.gz

MAINTAINER=	petri.totterman@hmv.fi
COMMENT=	A logging library for C++

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
MAKE_JOBS_UNSAFE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.apl ${PREFIX}/include/log4cplus
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/*.config ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/docs/html/*.html ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/docs/html/*.png ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/docs/html/doxygen.css ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/docs/html/graph_legend.dot ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
