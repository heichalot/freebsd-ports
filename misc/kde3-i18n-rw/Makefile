# New ports collection makefile for:    kde3-i18n-rw
# Date created:                         22 January 2005                             
# Whom:                                 Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	4
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src/kde-i18n
PKGNAMEPREFIX=	rw-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kinyarwanda messages and documentation for KDE3

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
