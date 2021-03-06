# New ports collection makefile for:	mailscanner-mrtg
# Date created:		2004-01-27
# Whom:			services-root <root@services.intern.seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	mailscanner-mrtg
PORTVERSION=	0.11.00
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	SF/mailscannermrtg/${PORTNAME}-UNSTABLE/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows mrtg to monitor many aspects of your MailScanner machine

RUN_DEPENDS=	${LOCALBASE}/bin/mrtg:${PORTSDIR}/net-mgmt/mrtg \
		${LOCALBASE}/lib/MailScanner/MailScanner.pm:${PORTSDIR}/mail/mailscanner

USE_PERL5=	yes
USE_APACHE=	1.3

PKGMESSAGE=	${WRKDIR}/pkg-message

WWWBASE=	${PREFIX}/www

MAN8=		mailscanner-mrtg.8

.include <bsd.port.pre.mk>

WWWFILES=	mailscanner-mrtg.conf \
		mailscanner-mrtg.cfg
ETCFILES=	${WWWFILES}

SUB_FILES+=	pkg-message

do-build:
.for FILE in ${WWWFILES}
	${PERL} -pi -e \
	's,/var/www/html,${WWWBASE},g; \
	s,/usr/sbin/mailscanner-mrtg,${PREFIX}/sbin/mailscanner-mrtg,g;' \
	${WRKSRC}/${FILE}
.endfor

	${PERL} -pi -e \
	's,/usr/bin/snmpwalk,${LOCALBASE}/bin/snmpwalk,g; \
	s,/etc/rc.d/init.d/MailScanner,${LOCALBASE}/etc/rc.d/mailscanner.sh,g;' \
	${WRKSRC}/mailscanner-mrtg.conf

	${PERL} -pi -e \
	's,/usr/lib/MailScanner-MRTG,${PREFIX}/lib/MailScanner-MRTG,g; \
	s,/etc/MailScanner/mailscanner-mrtg.(conf|thresholds),${PREFIX}/etc/mailscanner-mrtg/mailscanner-mrtg.$$1,g;' \
	${WRKSRC}/mailscanner-mrtg

do-install:
	#
	# Step 1: Install lib
	#
	${MKDIR} ${PREFIX}/lib/MailScanner-MRTG/MSMRTG
	${CHMOD} -R ${BINMODE} ${PREFIX}/lib/MailScanner-MRTG/MSMRTG
	cd ${WRKSRC}/lib/MSMRTG && ${FIND} * -name "*.pm" -exec \
		${INSTALL_SCRIPT} {} ${PREFIX}/lib/MailScanner-MRTG/MSMRTG \;

	#
	# Step 2: Install etc files
	#
	${MKDIR} ${PREFIX}/etc/mailscanner-mrtg
	${CHMOD} ${BINMODE} ${PREFIX}/etc/mailscanner-mrtg
.for FILE in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/etc/mailscanner-mrtg/${FILE}.sample
.endfor

	#
	# Step 3: Install binaries
	#
	${MKDIR} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/mailscanner-mrtg ${PREFIX}/sbin

	#
	# Step 4: Install Documentation & Manpages
	#
	${INSTALL_MAN} ${FILESDIR}/${MAN8} ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

	#
	# Step 5: Install Web Environment
	#
	${MKDIR} ${WWWBASE}/mailscanner-mrtg
	${INSTALL_DATA} ${WRKSRC}/web/* ${WWWBASE}/mailscanner-mrtg

	#
	# Step 6: Show further instructions
	#
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
