# New ports collection makefile for:	p5-Tcl-Tk
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tcl-Tk
PORTVERSION=	0.97
CATEGORIES=	x11-toolkits lang perl5 tk
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module to access to Tk via the Tcl extension

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tcl.pm:${PORTSDIR}/lang/p5-Tcl
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

PERL_CONFIGURE=	yes

MAN3=		Tcl::Tk.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BROKEN=		something segfaults during build
.endif

.include <bsd.port.post.mk>
