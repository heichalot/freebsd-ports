# ports collection makefile for:        Firebird BBS
# Date created:                         Sun Feb  4 22:48:06 CST 2001
# Whom:                                 Edward Chuang <edwardc@firebird.org.tw>
# $FreeBSD$

PORTNAME=	firebird
PORTVERSION=	3.0R
PORTREVISION=	1
CATEGORIES=	chinese net
MASTER_SITES=	ftp://ftp.isu.edu.tw/pub/Unix/BBS/FireBird/ftp.firebird.org.tw/
DISTNAME=	3.0-RELEASE

MAINTAINER=	edwardchuang@gmail.com
COMMENT=	A Common BBS Server with its own customized INN News Server

WRKSRC=		${WRKDIR}/bbs/bbssrc
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
IS_INTERACTIVE=	yes
NOT_FOR_ARCHS=	amd64

pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/bbs.sh.example ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/bbs.sh.example startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/bbs.sh.example ${PREFIX}/etc/rc.d/bbs.sh.example; \
	fi
	@${ECHO} "======================================================================="
	@${ECHO} "Installation Complete."
	@${ECHO} "======================================================================="
	@${ECHO} "please review ${PREFIX}/etc/rc.d/bbs.sh.example change bbsd port you want"
	@${ECHO} "then rename to ${PREFIX}/etc/rc.d/bbs.sh then:"
	@${ECHO} "use ${PREFIX}/etc/rc.d/bbs.sh { start | stop } to start the BBS service"
	@${ECHO} "full and complete document in ${PREFIX}/bbs/bbssrc/doc read before ask."

.include <bsd.port.mk>
