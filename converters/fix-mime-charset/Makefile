# New ports collection makefile for:	fix-mime-charset
# Date created:				26 November 2003
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	fix-mime-charset
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	converters textproc russian ukrainian
MASTER_SITES=	SF/fix-mime-chr/${PORTNAME}/${PORTVERSION}

MAINTAINER=	chip-set@mail.ru
COMMENT=	Fix incorrect Content-Type MIME headers of e-mail messages

LIB_DEPENDS=	enca.5:${PORTSDIR}/converters/enca

PORTDOCS=	README.koi8r README

GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		fix-mime-charset.1
PLIST_FILES=	bin/fix-mime-charset

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
