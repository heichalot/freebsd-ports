# New ports collection makefile for:	fireprofile
# Date created:		Mon 13 May 15:00:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	fireprofile
PORTVERSION=    0.1.2
PORTREVISION=	1
CATEGORIES=     databases
MASTER_SITES=   http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
DISTNAME=	fireprofile
EXTRACT_SUFX=   -0.1.2.tar.gz

MAINTAINER=     dean@odyssey.apana.org.au
COMMENT=	Library to help profiling where programs are using MySQL

MAN3=		libfireprofile.3
PLIST_FILES=	lib/libfireprofile.so.0 lib/libfireprofile.so

USE_LDCONFIG=	yes
USE_MYSQL=	yes
DEFAULT_MYSQL_VER=	323
WANT_MYSQL_VER=	323

post-install:
		$(LN) ${PREFIX}/lib/libfireprofile.so ${PREFIX}/lib/libfireprofile.so.0

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
