# New ports collection makefile for:	demime
# Date Created:				25 April 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	demime
PORTVERSION=	1.1d
PORTREVISION=	1
CATEGORIES=	mail textproc
MASTER_SITES=	http://freebsd.dev-urandom.com/distfiles/demime/ \
		http://www.glenbarber.us/ports/mail/demime/
DISTFILES=	${PORTNAME}.${PORTVERSION} demime_junkmail.cf

MAINTAINER=	glen.j.barber@gmail.com
COMMENT=	A tool to scrub mime from mailing lists

RUN_DEPENDS=	${SITE_PERL}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTML/FormatText.pm:${PORTSDIR}/textproc/p5-HTML-Format \
		${SITE_PERL}/HTML/Element.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset

NO_BUILD=	yes

USE_PERL5=	yes
POD2MAN?=	pod2man
MAN1=		demime.1

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/demime.${PORTVERSION}  ${WRKSRC}/demime

post-patch:
	@${REINPLACE_CMD} -e 's!/usr/lib/majordomo/demime_junkmail.cf!${PREFIX}/etc/demime_junkmail.cf!g' ${WRKSRC}/demime

do-install:
	${INSTALL_SCRIPT} -c ${WRKSRC}/demime ${PREFIX}/bin/demime
	${INSTALL_DATA} ${DISTDIR}/demime_junkmail.cf ${PREFIX}/etc
	${POD2MAN} ${WRKSRC}/demime > ${PREFIX}/man/man1/demime.1

.include <bsd.port.mk>
