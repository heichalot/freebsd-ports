# New ports collection makefile for:	nkf
# Date created:		5 February 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nkf
PORTVERSION=	2.1.0
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES?=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/44486
PKGNAMEPREFIX?=	ja-

MAINTAINER=	nork@FreeBSD.org
COMMENT?=	Network Kanji code conversion Filter

.if ${PKGNAMEPREFIX} != "ja-p5-"
MAN1=		nkf.1
MANLANG=	"" ja
PLIST_FILES=	bin/nkf
ALL_TARGET=	nkf
.endif

.include <bsd.port.mk>
