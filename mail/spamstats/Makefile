# New ports collection makefile for:	spamstats
# Date created:				14 March 2003
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spamstats
PORTVERSION=	0.6c
CATEGORIES=	mail
MASTER_SITES=	http://www.inl.fr/download/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A tool to generate statistics for spamd of Mail::SpamAssassin

RUN_DEPENDS=	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Compress/Bzip2.pm:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip

USE_PERL5=	yes
NO_BUILD=	yes
PORTDOCS=	QUICK README copyright
PLIST_FILES=	bin/spamstats.pl

post-patch:
	@${PERL} -pi.bak -e 's,/mail.log,/maillog,g' ${WRKSRC}/${PORTNAME}${PORTVERSION}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}${PORTVERSION}.pl ${PREFIX}/bin/${PORTNAME}.pl
.ifndef	(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
