# New ports collection makefile for:	cryptplug
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	cryptplug
PORTVERSION=	0.3.16
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/cryptplug

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of plug-ins to cryptographic engines

BUILD_DEPENDS=	${LOCALBASE}/lib/libgpgme03.so.9:${PORTSDIR}/security/gpgme03 \
		gpg-agent:${PORTSDIR}/security/gnupg

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's/gpgme-config/gpgme03-config/g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
