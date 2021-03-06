# New ports collection Makefile for: RT-Extension-LDAPImport
# Date created:	        24 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Extension-LDAPImport
PORTVERSION=	0.07
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to import users from an LDAP store

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS=	RT36 "Install for rt-3.6.x (default rt-3.8.x)" off

.include <bsd.port.options.mk>

.if defined(WITH_RT36)

RTHOME?=	rt3
RT_PM_DIR=	${LOCALBASE}/${RTHOME}/lib
BUILD_DEPENDS+=	${RT_PM_DIR}/RT.pm:${PORTSDIR}/www/rt36
PLIST=		${PKGDIR}/pkg-plist.rt36
MAN3PREFIX=	${PREFIX}/${RTHOME}/local

.else

RTHOME?=	share/rt38
RT_PM_DIR=	${SITE_PERL}
BUILD_DEPENDS+=	${RT_PM_DIR}/RT.pm:${PORTSDIR}/www/rt38
PLIST=		${PKGDIR}/pkg-plist.rt38
MAN3PREFIX=	${PREFIX}

.endif

MAN3=		RT::Extension::LDAPImport.3
PLIST_SUB+=	RTHOME=${RTHOME}

post-patch:
	@${REINPLACE_CMD} -e 's,/opt/rt3/lib,${RT_PM_DIR},' \
	    ${WRKSRC}/bin/rtldapimport && \
	    ${RM} ${WRKSRC}/bin/rtldapimport.bak

# Note: You can install using an arbitrary $PREFIX but only if it
# matches the $PREFIX used to install www/rt3{6,8}.  Hence ignore
# $PREFIX in the environment and inherit settings from RT.pm
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    unset PREFIX && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} -I${RT_PM_DIR} ./${CONFIGURE_SCRIPT} && \
	    ${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
