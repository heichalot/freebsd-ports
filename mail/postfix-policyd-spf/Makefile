# New ports collection makefile for:	policyd
# Date created:				19 Dec 2004
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		policyd
PORTVERSION=		1.0.1
PORTREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://www.libspf2.org/patch/
PKGNAMEPREFIX=		postfix-
PKGNAMESUFFIX=		-spf

MAINTAINER=		mnag@FreeBSD.org
COMMENT=		Implements SPF for postfix, as a policy daemon

LIB_DEPENDS=		spf2.1:${PORTSDIR}/mail/libspf2-10

CONFLICTS=		policyd-1.*

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=		CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib"
GNU_CONFIGURE=		yes

PKGMESSAGE=		${WRKDIR}/pkg-message
SUB_FILES=		pkg-message

PLIST_FILES=		sbin/postfix-policyd-spf

DOCSDIR=		${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
