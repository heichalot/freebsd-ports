# New ports collection makefile for:	libpperl
# Date created:			December 14, 2005
# Whom:				Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpperl
PORTVERSION=	20051214
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~kbyanc/ \
		http://www.posi.net/software/libpperl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library easing embedding perl interpreters into C programs

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_PERL5=	5.8.0+

.include <bsd.port.mk>
