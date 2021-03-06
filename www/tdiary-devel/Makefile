# New ports collection makefile for:    tdiary-devel
# Date created:                 9 June 2005
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	tdiary
PORTVERSION=	2.3.3
CATEGORIES?=	www ruby
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ \
		http://www.tdiary.org/download/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-full-${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A Web-based diary system (like weblog) written in Ruby

.if defined(WITH_FCGI)
RUN_DEPENDS=	${RUBY_SITELIBDIR}/fcgi.rb:${PORTSDIR}/www/ruby-fcgi
.endif

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_REQUIRE=	Ruby >= 182
PORTSCOUT=	limitw:1,odd

RUBY_SHEBANG_FILES=	index.fcgi \
			index.rb \
			update.rb \
			misc/convert2.rb \
			misc/migrate.rb \
			misc/plugin/amazon/amazonimg.rb \
			misc/plugin/pingback/pb.rb \
			misc/plugin/squeeze.rb \
			misc/plugin/trackback/tb.rb \
			misc/plugin/xmlrpc/xmlrpc.rb \
			misc/style/etdiary/etdiary_test.rb \
			tdiary/wiki_style_test.rb \
			theme/themebench.rhtml

PORTDOCS=	ChangeLog COPYING HOWTO-make-io.rd HOWTO-make-plugin.html \
		HOWTO-make-theme.html HOWTO-use-plugin.html \
		HOWTO-write-tDiary.en.html HOWTO-write-tDiary.html INSTALL.html \
		README.en.html README.html UPGRADE doc.css

SUB_FILES=	pkg-message tdiaryinst.rb
SUB_LIST+=	TDIARY_LANG=${TDIARY_LANG} \
		TDIARY_SCRIPT=${TDIARY_SCRIPT}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}${PKGNAMESUFFIX}
WWWDIR=		${PREFIX}/www/${UNIQUENAME}${PKGNAMESUFFIX}

TDIARY_SCRIPT=	${UNIQUENAME}${PKGNAMESUFFIX}-inst.rb

#TDIARY_LANG	ja:Japanese en:English zh:Traditional-Chinese
.if !defined(TDIARY_LANG) || ( defined(TDIARY_LANG) && ${TDIARY_LANG} != ja )
TDIARY_LANG=	en
.endif

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
.if !defined(RUBY_PROVIDED)
IGNORE=	requires Ruby 1.9.1 or later
.endif
.endif

.if ${RUBY_VER} == 1.8
.if !defined(RUBY_PROVIDED)
IGNORE=	requires Ruby 1.8.2 or later
.endif
.if !defined(WITHOUT_TDIARY_NORA)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -f README && ${MV} ChangeLog doc
	@cd ${WRKSRC} && ${MV} doc ${WRKDIR}

pre-install:
	@${SED} -e 's,#!/usr/bin/env ruby,#!${RUBY},' \
		${WRKDIR}/tdiaryinst.rb > ${WRKDIR}/${TDIARY_SCRIPT}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${TDIARY_SCRIPT} ${PREFIX}/bin
	@-${MKDIR} ${WWWDIR}
	@${CP} -pR ${WRKSRC}/ ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} bin/${TDIARY_SCRIPT} >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKDIR}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
