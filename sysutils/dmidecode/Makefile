# New ports collection makefile for:	dmidecode
# Date created:				19 November 2003
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dmidecode
PORTVERSION=	2.10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		ftp://ftp.nuug.no/pub/anders/distfiles/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A tool for dumping DMI (SMBIOS) contents in human-readable format

ONLY_FOR_ARCHS=	i386 amd64 ia64

USE_BZIP2=	yes
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" DOCSDIR="${DOCSDIR}"

PORTDOCS=	AUTHORS CHANGELOG README

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install.*:/s,install-doc,,' ${WRKSRC}/Makefile
.endif

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>

MAN8=		dmidecode.8
PLIST_FILES=	sbin/dmidecode
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
MAN8+=		biosdecode.8 ownership.8 vpddecode.8
PLIST_FILES+=	sbin/biosdecode sbin/ownership sbin/vpddecode
.endif

.include <bsd.port.post.mk>
