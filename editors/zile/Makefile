# New ports collection Makefile for:	zile
# Date created:		28 September 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	zile
PORTVERSION=	2.3.16
CATEGORIES=	editors
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small emacs-like text editor

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--without-included-regex

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/FAQ %%DATADIR%%/dotzile.sample
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS=	-isystem /usr/include/gnu
LDFLAGS=	-lgnuregex

post-patch:
	@${REINPLACE_CMD} -e \
		'/need_charset_alias=/s|true|false|g' ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
