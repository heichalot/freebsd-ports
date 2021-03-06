# New ports collection makefile for:	gnulib
# Date created:		20 March 2010
# Whom:			Johans van Selst <johans@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnulib
PORTVERSION=	20100704
CATEGORIES=	devel
MASTER_SITES=	http://erislabs.net/ianb/projects/gnulib/
DISTNAME=	${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU portability library

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GMAKE=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/check-module bin/gnulib-tool
INFO=		${PORTNAME}
PORTDATA=	*

.ifdef		NOPORTDATA
IGNORE=		gnulib requires port data, unset NOPORTDATA to install
.endif

.ifndef		NOPORTDOCS
PLIST_DIRS+=	%%DOCSDIR%%
PLIST_FILES+=	%%DOCSDIR%%/${PORTNAME}.html
.endif

post-patch:
	${REINPLACE_CMD} -e 's/date -u.*/stat -f %Sa -t "@set UPDATED %F %T" `ls -t $$^ | sed 1q` > $$@/' ${WRKSRC}/doc/Makefile
	${REINPLACE_CMD} -e '1s@/bin/sh@${LOCALBASE}/bin/bash@' \
		${WRKSRC}/gnulib-tool

do-build:
	cd ${WRKSRC} && ${GMAKE} -C doc info html

do-install:
	${MKDIR} ${DATADIR} ${PREFIX}/${INFO_PATH}
	for p in check-module gnulib-tool;\
		do ${INSTALL_SCRIPT} ${WRKSRC}/$$p ${DATADIR};\
		cd ${PREFIX}/bin && ${LN} -s ${DATADIR}/$$p;\
		done
	cd ${WRKSRC} && \
		${CP} -Rp build-aux config doc lib m4 modules tests ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.info ${PREFIX}/${INFO_PATH}
.ifndef		NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
