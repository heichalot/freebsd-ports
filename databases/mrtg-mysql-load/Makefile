# New ports collection makefile for:	mrtg-mysql-load
# Date created:		2004-04-08
# Whom:			Piet Delport <pjd@303.za.net>
#
# $FreeBSD$
#

PORTNAME=	mrtg-mysql-load
PORTVERSION=	1.02
PORTREVISION=	4
CATEGORIES=	databases net-mgmt
MASTER_SITES=	http://www.bitbybit.dk/mysql/mrtg-mysql-load/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A MySQL load analysis fetcher for MRTG

RUN_DEPENDS=	mrtg:${PORTSDIR}/net-mgmt/mrtg

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5_RUN=	yes
USE_MYSQL=	yes

MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PERL%%|${PERL}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/mrtg
	@${INSTALL_DATA} ${WRKSRC}/mrtg-cfg.example  ${PREFIX}/etc/mrtg/mrtg.cfg-mysql-load.example
	@${INSTALL_DATA} ${WRKSRC}/mysql-load-cfg.example  ${PREFIX}/etc/mrtg/mysql-load-cfg.example
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
