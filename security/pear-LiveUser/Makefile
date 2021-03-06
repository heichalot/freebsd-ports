# Ports collection makefile for:  pear-LiveUser
# Date created:			  29 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	LiveUser
PORTVERSION=	0.16.13
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR user authentication and permission management framework

BUILD_DEPENDS=	${PEARDIR}/Event/Dispatcher.php:${PORTSDIR}/devel/pear-Event_Dispatcher
RUN_DEPENDS=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.61

LATEST_LINK=	pear-LiveUser
OPTIONS=	PEAR_DB "PEAR::DB support" off \
		PEAR_MDB "PEAR::MDB support" off \
		PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_LOG "PEAR::Log support" off \
		PEAR_XML_TREE "PEAR::XML_Tree support" off \
		PEAR_CRYPT_RC4 "PEAR::Crypt_RC4 support" off

CATEGORY=	LiveUser
FILES=		Auth/Common.php Auth/DB.php Auth/MDB.php Auth/MDB2.php \
		Auth/PEARAuth.php Auth/PDO.php Auth/Session.php Auth/XML.php \
		Perm/Storage/DB.php Auth/Storage/Globals.php Perm/Storage/MDB.php \
		Perm/Storage/MDB2.php Perm/Storage/PDO.php Perm/Storage/SQL.php \
		Perm/Storage/XML.php Perm/Complex.php Perm/Medium.php Perm/Simple.php \
		Perm/Storage.php LiveUser.php
SQLS=		Auth_XML.xml install.php Perm_XML.xml README
DOCS=		lgpl.txt
EXAMPLES=	example1/Auth_XML.xml example1/conf.php example1/example.php \
		example1/index.html example1/README example2/Auth_XML.xml \
		example2/conf.php example2/example.php example2/index.html \
		example2/Perm_XML.xml example2/README example4/Auth_XML.xml \
		example4/conf.php example4/demodata.xml example4/error-page.tpl.php \
		example4/finish.inc.php example4/functions.js example4/index.html \
		example4/loginform.tpl.php example4/news_change.php \
		example4/news_change.tpl.php example4/news_new.php \
		example4/news_new.tpl.php example4/news_notallowed.tpl.php \
		example4/news_view.php example4/news_view.tpl.php \
		example4/style.css  example5/admin.php example5/admin.tpl \
		example5/conf.php example5/conf_pdo.php example5/createlu.php \
		example5/demodata.xml example5/home.php example5/home.tpl \
		example5/index.php example5/layout_frontend.css \
		example5/liveuser_rights.php example5/login_form.tpl \
		example5/news.tpl example5/news_edit.tpl \
		example5/news_list.tpl  demodata.php
_EXAMPLESDIR=	docs/examples
_DOCSDIR=	.

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_DB)
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if defined(WITH_PEAR_MDB)
RUN_DEPENDS+=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB
.endif

.if defined(WITH_PEAR_MDB2)
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	 ${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if defined(WITH_PEAR_XML_TREE)
RUN_DEPENDS+=	${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree
.endif

.if defined(WITH_PEAR_CRYPT_RC4)
RUN_DEPENDS+=	${PEARDIR}/Crypt/Rc4.php:${PORTSDIR}/security/pear-Crypt_RC4
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
