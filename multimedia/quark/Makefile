# New ports collection makefile for:	multimedia/quark
# Date created:		21 Jul 2003
# Whom:			Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$

PORTNAME=	quark
PORTVERSION=	3.21
PORTREVISION=	21
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://quark.sunsite.dk/ \
		http://demian.dyndns.org/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An audio player, for geeks, by geeks

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine

USE_GNOME=	gnomehack gnomeprefix gnometarget gnomevfs2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	AUTHORS COPYING INSTALL README
GCONF_SCHEMAS=	quark.schemas strange-quark.schemas

post-patch:
	@${REINPLACE_CMD} -e \
		's|CFLAGS="-g |CFLAGS="$$CFLAGS |g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
