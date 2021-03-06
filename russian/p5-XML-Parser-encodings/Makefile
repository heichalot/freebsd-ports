# New ports collection makefile for:	XML::Encoding
# Date created:		15 Oct 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Parser-encodings
PORTVERSION=	1.02
CATEGORIES=	russian textproc perl5
PKGNAMEPREFIX=	p5-
DISTFILES=

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Additional russian encodings for XML::Parser

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/XML/Encoding.pm:${PORTSDIR}/textproc/p5-XML-Encoding \
		${NONEXISTENT}:${PORTSDIR}/converters/iconv:extract \
		${NONEXISTENT}:${PORTSDIR}/converters/iconv-extra:extract

NO_WRKSUBDIR=	YES
USE_PERL5=	YES
RUSSIANENC=	windows-1251 koi8-r cp1251 cp866 mac-cyrillic

post-extract:
.for ICONVPORT in iconv iconv-extra
	@${LN} -sfh \
	`cd ${PORTSDIR}/converters/${ICONVPORT} && ${MAKE} -V WRKSRC`/ccs \
	${WRKSRC}/${ICONVPORT}
.endfor

do-configure:
.for ENC in koi8-r cp866
	@${CP} ${WRKSRC}/iconv/${ENC}.txt ${WRKDIR}
.endfor
.for ENC in mac-cyrillic windows-1251
	@${CP} ${WRKSRC}/iconv-extra/${ENC}.txt ${WRKDIR}
.endfor
	@${CP} ${WRKDIR}/windows-1251.txt ${WRKDIR}/cp1251.txt
	@${PERL} -pi -e 's/\r/\n/gm;' ${WRKDIR}/mac-cyrillic.txt

do-build:
.for ENC in ${RUSSIANENC}
	@${PREFIX}/bin/make_encmap ${ENC} ${WRKDIR}/${ENC}.txt | \
	${PERL} -pi -e "s/(?<=^<encmap name='${ENC}')()(?=>)/ expat='yes'/;" \
		>${WRKDIR}/${ENC}.xml
	@${PREFIX}/bin/compile_encoding \
		-o ${WRKDIR}/${ENC}.enc ${WRKDIR}/${ENC}.xml
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.enc \
		${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/XML/Parser/Encodings/

.include <bsd.port.mk>
