# New ports collection makefile for:	WOTS
# Date created:				26-Nov-2001
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wots
PORTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	http://www.hpcc.uh.edu/~tonyc/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System log watch/alert utility, similar to swatch, written in Perl

BUILD_DEPENDS=	${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	--perl=${PERL}
NO_BUILD=	yes

MAN1=		wots.1
PLIST_FILES=	bin/wots

post-extract:
	@${CHMOD} a+x ${WRKSRC}/Configure

post-patch:
	@${REINPLACE_CMD} -i '' -e 's/5.00\[4/5.0[01][04/' \
		${WRKSRC}/Configure
	@${REINPLACE_CMD} -i '' -e 's=/usr/local=${PREFIX}=; s=/usr/bin/perl=${PERL}=' \
		${WRKSRC}/Make.config

.include <bsd.port.mk>
