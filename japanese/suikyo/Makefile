# New ports collection makefile for:	ja-suikyo
# Date created:				6 Jun 2003
# Whom:					Gen Otsuji<otsuji@users.sourceforge.jp>
#
# $FreeBSD$
#

PORTNAME=	suikyo
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://prime.sourceforge.jp/src/

MAINTAINER=	otsuji@users.sourceforge.jp
COMMENT=	Romaji-Kana conversion Library for the prime

USE_RUBY=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rubydir=${RUBY_SITELIBDIR}
USE_AUTOTOOLS=	automake:19 autoconf:262

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc; ${MAKE} ${INSTALL_TARGET}
	cd ${WRKSRC}/elisp/doc; ${MAKE} ${INSTALL_TARGET}
	cd ${WRKSRC}/ruby/doc; ${MAKE} ${INSTALL_TARGET}
.endif

.include <bsd.port.mk>
