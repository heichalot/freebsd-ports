# ex:ts=8
# Ports collection makefile for:	netspoc
# Date created:			Nov 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netspoc
PORTVERSION=	3.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://download.berlios.de/netspoc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Network Security Policy Compiler

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		netspoc.1
DOCS=		CSPM.html NEWS.html index.html language.html netspoc.html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netspoc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Netspoc.pm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/netspoc.man ${MANPREFIX}/man/man1/netspoc.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
