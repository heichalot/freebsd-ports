# New ports collection makefile for:	ocaml-calendar
# Date created:				Feb 26, 2007
# Whom:					Jaap Boender <jaapb@kerguelen.org>
#
# $FreeBSD$
#

PORTNAME=	calendar
PORTVERSION=	2.01.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.lri.fr/~signoles/prog/calendar/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	A date and time library for OCaml

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes

post-install:
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}

.include <bsd.port.mk>
