# New ports collection makefile for:	tcm
# Date created:				18 July 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	tcm
PORTVERSION=	2.20
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.utwente.nl/pub/tcm/ \
		ftp://ftp.cs.vu.nl/pub/tcm/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	lawrance
PATCHFILES=	patch-tcm-64bit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Toolkit for Conceptual Modeling, create diagrams/tables/trees

RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

USE_BISON=	build
USE_GMAKE=	yes
USE_MOTIF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES+=	pkg-message

MANPREFIX=	${PREFIX}/tcm
MAN1=		psf.1 tatd.1 tcbd.1 tcm.1 tcmd.1 tcmdv.1 tcmt.1 tcpd.1 tcrd.1 \
		tdfd.1 tdpd.1 tefd.1 terd.1 tesd.1 text2ps.1 tfet.1 tfrt.1 \
		tgd.1 tgt.1 tgtt.1 tpsd.1 trpg.1 tscd.1 tsnd.1 tssd.1 tstd.1 \
		ttdt.1 ttut.1 tucd.1

post-patch:
	@${RM} ${WRKSRC}/man/windex
	@${CHMOD} 0644 ${WRKSRC}/lib/colorrgb.txt
	@${REINPLACE_CMD} -e 's:gcc:g++:g' ${WRKSRC}/bin/makedepend.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
