# New ports collection makefile for:	putty
# Date created:		13 Feb 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	putty
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/%SUBDIR%/ \
		ftp://ftp.chiark.greenend.org.uk/users/sgtatham/putty-latest/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Secure shell and telnet client

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
MAKEFILE=	Makefile.gtk
CFLAGS+=	-DBSD_PTYS -DOMIT_UTMP

PLIST_FILES=	bin/plink bin/pscp bin/psftp bin/puttygen
MAN1=		plink.1 pscp.1 psftp.1 puttygen.1

.if !defined(WITHOUT_GTK)
USE_GNOME=	gtk12
PLIST_FILES+=	bin/pterm bin/putty bin/puttytel
MAN1+=		pterm.1 putty.1 puttytel.1
MAKE_ENV+=	PUTTY_WITH_GTK=yes
CFLAGS+=	`${GTK_CONFIG} --cflags`
.endif

.if !defined(WITHOUT_IPV6)
CFLAGS+=	-DIPV6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,gtk-config,${GTK_CONFIG},g; \
			      s,prefix=/usr/local,prefix=${PREFIX},' \
		${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
