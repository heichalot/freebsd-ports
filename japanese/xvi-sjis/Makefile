# New ports collection makefile for:	ja-xvi-sjis
# Date created:		07 Aug 2002
# Whom:			KIMURA<LEE> Shigekazu <spbz6f99@utopia.ocn.ne.jp>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-sjis

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable multi-window 'vi', handles Japanese SJIS

MASTERDIR=	${.CURDIR}/../xvi-euc

PATCHDIR=	${.CURDIR}/files

EXTRA_PATCHES=	${MASTERDIR}/files/patch-unix.h

PLIST=		${.CURDIR}/pkg-plist

PROG=		sxvi

.include "${MASTERDIR}/Makefile.common"
