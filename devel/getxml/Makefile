# ex:ts=8
# New ports collection makefile for:	getxml
# Date created:			Jul 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	getxml
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XML internationalization tool

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

USE_GNOME=	glib12
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,glib-config,${GLIB_CONFIG},g" ${WRKSRC}/configure

.include <bsd.port.mk>
