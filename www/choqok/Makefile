# New ports collection makefile for:	Choqok
# Date created:				15 Sep 2009
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	choqok
PORTVERSION=	0.6.6
PORTREVISION=	4
CATEGORIES=	www kde
MASTER_SITES=	http://mirror.umoss.org/download.ospdev.net/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE micro-blogging client

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	gui network imageformats_run moc_build \
		qmake_build rcc_build uic_build

.include <bsd.port.mk>
