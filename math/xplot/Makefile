# New ports collection makefile for:	xplot
# Date created:		3 March 1997
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	xplot
PORTVERSION=	0.90.7.1
PORTREVISION=	2
CATEGORIES=	math graphics net
MASTER_SITES=	http://www.xplot.org/xplot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 plotting package

GNU_CONFIGURE=	yes

#XPLOT_DEMOS=	demo.0 demo.1 demo.2 demo.3 demo.4 demo.5 demo.6 demo.7

USE_XORG=	x11
MAN1=		tcpdump2xplot.1 xplot.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tcpdump2xplot.pl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xplot
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xplot
	${INSTALL_DATA} ${WRKSRC}/README.tcp_plots ${PREFIX}/share/doc/xplot
.endif
#	${MKDIR} ${PREFIX}/share/examples/xplot
#.for i in ${XPLOT_DEMOS}
#	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/xplot
#.endfor

.include <bsd.port.mk>
