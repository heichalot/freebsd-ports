# ex:ts=8
# New ports collection makefile for:   dotconf
# Date created:                Jan 28, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dotconf
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.azzit.de/dotconf/download/v1.1/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple, powerful configuration-file parser

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|-Wall -g||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-release $(LT_RELEASE)||' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples  -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
