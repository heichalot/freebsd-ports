# New ports collection makefile for:   rainbowcrack
# Date created:        8 May 2006
# Whom:                bryan@freshdns.net
#
# $FreeBSD$
#

PORTNAME=	rainbowcrack
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.semprixd.com/shares/ports/

MAINTAINER=	semprix@bsdmail.org
COMMENT=	Hash cracker that precomputes plaintext - ciphertext pairs in advance

USE_DOS2UNIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|g++|$$(CXX) $$(CXXFLAGS)|; s|\-O3||' \
		${WRKSRC}/${MAKEFILE}

do-install:
.for f in rcrack rtgen rtdump rtsort
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/charset.txt ${EXAMPLESDIR}

.include <bsd.port.post.mk>
