# New ports collection makefile for:	Metacity theme microGUI
# Date created:	23 April 2004
# Whom:	Douglas Thrift <douglas@douglasthrift.net>
#
# $FreeBSD$
#

PORTNAME=	microgui
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
DISTNAME=	mcitymicrogui-default

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	The microGUI Sawfish theme for Metacity

USE_GNOME=	gnomehier

RESTRICTED=	${REASON}

WRKSRC=		${WRKDIR}/microGUI

.include "${.CURDIR}/../metacity-themes/Makefile.metacity"
.include <bsd.port.mk>
