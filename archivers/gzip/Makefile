# New ports collection makefile for:	gzip
# Date created:				27 July 2002
# Whom:					cyrille.lefevre@laposte.net
#
# $FreeBSD$
#

PORTNAME=	gzip
PORTVERSION=	1.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	A compression utility designed to be a replacement for compress

GNU_CONFIGURE=	yes

MAN1=	gunzip.1 gzexe.1 gzip.1 zcat.1 zcmp.1 zdiff.1 zforce.1 \
	zgrep.1 zless.1 zmore.1 znew.1
INFO=	gzip

DOC_FILES=	AUTHORS COPYING ChangeLog ChangeLog-2007 INSTALL NEWS README \
		THANKS TODO

post-configure:
	@${REINPLACE_CMD} -e 's|^SHELL =.*|SHELL=/bin/sh|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|need_charset_alias=true|need_charset_alias=false|g' \
		${WRKSRC}/lib/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
