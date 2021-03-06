# New ports collection makefile for:	cons-test
# Date created:		15 September 2000
# Whom:			rv@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cons-test
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.dsmit.com/cons/stable/ \
		http://www.gnu.org/software/cons/stable/ \
		ftp://ftp.gnu.org/pub/gnu/cons/ \
		http://www.baldmt.com/cons/stable/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A test bed for `Cons' development

RUN_DEPENDS=	${LOCALBASE}/bin/cons:${PORTSDIR}/devel/cons

USE_PERL5=	yes
NO_BUILD=	yes
CONS_TEST=	cons-${PORTVERSION}/test
WRKSRC=		${WRKDIR}/${CONS_TEST}
PLIST_SUB+=	CONS_VER=${PORTVERSION} CONS_TEST=${CONS_TEST}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-test//}-${PORTVERSION}/test

MAN1=		cons-test.1
MANCOMPRESSED=	yes
DOCS=		CHANGES COPYING COPYRIGHT README TODO Tests.txt
TESTS=		1..83,101..147
TEST_LIBS=	Cmd.pm Cons.pm
do-install:
#
# Install the script
#
	${MKDIR} ${PREFIX}/bin
	@${SED} -e 's:/usr/lib:${PREFIX}/lib:g' \
		<${WRKSRC}/cons-test >${PREFIX}/bin/cons-test
	@${CHMOD} a+x ${PREFIX}/bin/cons-test

#
# Install the tests
#
	${MKDIR} ${PREFIX}/lib/${CONS_TEST}/t
	${PERL} -e 'for (${TESTS}) {$$f=sprintf "t%04d.t", $$_;\
		    $$x= "${INSTALL_DATA} ${WRKSRC}/t/$$f \
			    ${PREFIX}/lib/${CONS_TEST}/t";\
		    printf "$$x\n"; system $$x;}'
#
# Install the test libraries
#
	${MKDIR} ${PREFIX}/lib/${CONS_TEST}/Test/Cmd
	${INSTALL_DATA} ${WRKSRC}/Test/Cmd.pm ${PREFIX}/lib/${CONS_TEST}/Test
	${INSTALL_DATA} ${WRKSRC}/Test/Cmd/Cons.pm \
	    ${PREFIX}/lib/${CONS_TEST}/Test/Cmd
#
# Install the man pages
#
	${INSTALL_MAN} ${WRKSRC}/cons-test.1.gz \
		${PREFIX}/man/man1/cons-test.1.gz
.if !defined(NOPORTDOCS)
#
# Install the documentation
#
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL} -c ${WRKSRC}/$f \
		${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
