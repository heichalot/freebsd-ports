# New ports collection makefile for:    koffice-i18n-zh_CN
# Date created:                         21 January 2004
# Whom:                                 Brad Davis <so14k@so14k.com>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.6.3
PORTREVISION=	4
CATEGORIES?=	chinese kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/koffice-${PORTVERSION}/src/koffice-l10n
PKGNAMEPREFIX=	zh_CN-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simplified Chinese messages and documentation for koffice

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
