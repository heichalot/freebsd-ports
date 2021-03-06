# New ports collection makefile for:	GLPK
# Date created:		16 December 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glpk
PORTVERSION=	4.43
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	glpk

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A GNU Linear Programming Kit

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

OPTIONS=	IODBC	"Enable MathProg iodbc support" Off \
		MYSQL	"Enable MathProg mysql support" Off

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-trigraphs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-gmp --with-zlib

.include <bsd.port.pre.mk>

.ifdef(WITH_IODBC || WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-dl=dlfcn
.else
CONFIGURE_ARGS+=	--disable-dl
.endif

.ifdef(WITH_IODBC)
CONFIGURE_ARGS+=	--enable-odbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
.else
CONFIGURE_ARGS+=	--disable-odbc
.endif

.ifdef(WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-mysql
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

post-patch:
	@${REINPLACE_CMD} -e "s;\/usr\/include\/mysql;${LOCALBASE}\/include\/mysql;g" \
	${WRKSRC}/configure

.if !defined(NOPORTDOCS)
PORTDOCS=	glpk.pdf glpk_faq.txt gmpl.pdf graphs.pdf miplib2.txt miplib3.txt \
		netlib.txt opb.txt tables.pdf dfeas.pdf gomory.pdf keller.pdf prepro.pdf \
		scaling.pdf subset.pdf updating.pdf

post-install:
	@${CP} ${WRKSRC}/doc/notes/*.pdf ${WRKSRC}/doc/
	@${MKDIR} ${DOCSDIR}
	for docfile in ${PORTDOCS} ; do \
		${INSTALL_MAN} ${WRKSRC}/doc/$${docfile} ${DOCSDIR} ; \
	done

.endif

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
