# New ports collection makefile for:	policyd2
# Date created:				2 December 2008
# Whom:	      				Chifeng QU <chifeng@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	policyd2
PORTVERSION=	2.0.10
CATEGORIES=	mail
MASTER_SITES=	SF/policyd/2.0.x%20%28Stable%29/v${PORTVERSION}
DISTNAME=	cluebringer-${PORTVERSION}

MAINTAINER=	chifeng@gmail.com
COMMENT=	Policyd v2 is a multi-platform policy server for popular MTAs

RUN_DEPENDS=	${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/Net/CIDR.pm:${PORTSDIR}/net-mgmt/p5-Net-CIDR \
		${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		${SITE_PERL}/mach/Cache/FastMmap.pm:${PORTSDIR}/devel/p5-Cache-FastMmap

USE_PERL5=	yes
USE_PHP=	yes
NO_BUILD=	yes
USE_RC_SUBR=	policyd2.sh
SUB_FILES=	pkg-message

WEBUIDIR=	${PREFIX}/www/policyd
PORTDOCS=	AUTHORS CHANGELOG INSTALL TODO WISHLIST
PORTDATA=	*

OPTIONS=	MYSQL "Use MySQL support" On \
		SQLite "Use SQLite support" Off

.include <bsd.port.pre.mk>
USE_PHP=	pdo_mysql
.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif
.if defined(WITH_SQLite)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/cbpadmin
	@${REINPLACE_CMD} 's|/etc|${PREFIX}/etc|' ${WRKSRC}/cbpolicyd

do-install:
	@${INSTALL} -d ${WEBUIDIR}
	@cd ${WRKSRC} && ${CP} -Rpf webui/ ${WEBUIDIR}
	@cd ${WRKSRC} && ${CP} -Rpf cbp ${SITE_PERL}
	${INSTALL_SCRIPT} -m 0755 ${WRKSRC}/cbpadmin ${PREFIX}/bin
	${INSTALL_SCRIPT} -m 0755 ${WRKSRC}/cbpolicyd ${PREFIX}/bin
	${INSTALL_DATA} -m 0644 ${WRKSRC}/cluebringer.conf ${PREFIX}/etc/cluebringer.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/cluebringer.conf ]; then \
		${CP} -p ${PREFIX}/etc/cluebringer.conf.sample ${PREFIX}/etc/cluebringer.conf ; \
		${CHMOD} +w ${PREFIX}/etc/cluebringer.conf ; \
	fi

.if !defined(NOPORTDATA)
	@${INSTALL} -d ${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} contrib ${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} database ${DATADIR}
.endif

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
