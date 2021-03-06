# New ports collection makefile for:	cvsweb
# Date created:		27 Jun 1999
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsweb
PORTVERSION=	2.0.6
PORTREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~scop/cvsweb/
MASTER_SITE_SUBDIR=	scop

# For issues that are not specific to this port/package, please consult
# the <freebsd-cvsweb@FreeBSD.org> mailing list.
MAINTAINER=	noackjr@alumni.rice.edu
COMMENT=	WWW CGI script to browse CVS repository trees

CONFLICTS=	cvsweb-3.*

NO_BUILD=	yes
USE_PERL5=	yes

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

# Specify the title of your cvsweb site.
TITLE?=		My CVS Repository

# Specify these directories in relative paths to ${PREFIX}.
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
ICONSDIR?=	share/apache/icons
.else
CGIDIR?=	www/cgi-bin
ICONSDIR?=	www/icons
.endif

CONFFILES=	cvsweb.conf \
		cvsweb.conf-freebsd \
		cvsweb.conf-openbsd \
		cvsweb.conf-netbsd \
		cvsweb.conf-ruby

PLIST_SUB=	CGIDIR="${CGIDIR}" ICONSDIR="${ICONSDIR}"

SUB_FILES=	pkg-message
SUB_LIST=	PREFIX="${PREFIX}" DOCSDIR="${DOCSDIR}"

post-patch:
	${PERL} -i -pe "\
		s'!!PERL!!'${PERL}'g; \
		s'!!PREFIX!!'${PREFIX}'g;" \
		${WRKSRC}/cvsweb.cgi
	${PERL} -i -pe "\
		s'!!PREFIX!!'${PREFIX}'g; \
		s'!!CVSROOT!!'${CVSROOT}'g; \
		s'!!TITLE!!'${TITLE}'g;" \
		${WRKSRC}/cvsweb.conf

do-install:
	${MKDIR} ${PREFIX}/${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/${CGIDIR}/
	${MKDIR} ${PREFIX}/etc/cvsweb
.for f in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/cvsweb/${f}.dist
.endfor
	${MKDIR} ${PREFIX}/${ICONSDIR}/cvsweb
	${INSTALL_DATA} ${WRKSRC}/icons/* ${PREFIX}/${ICONSDIR}/cvsweb/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ChangeLog INSTALL README README.FreeBSD TODO TODO.FreeBSD
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

post-install:
.if defined(PACKAGE_BUILDING)
	${ECHO_CMD} "@unexec rmdir %D/${CGIDIR} %D/${ICONSDIR} 2>/dev/null || true" >> ${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
