# New ports collection makefile for:	qmail-ldap
# Date created:				21 May 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${LDAP_PATCH_DATE}
PORTREVISION=	4
CATEGORIES=	mail
PKGNAMESUFFIX=	-ldap

COMMENT=	A SECURE, reliable, and FAST MTA for UNIX systems WITH LDAP support

RUN_DEPENDS=	${LOCALBASE}/bin/svscan:${PORTSDIR}/sysutils/daemontools \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp

CONFLICTS=	emboss-[0-9]* digest-[0-9]* qmail-[0-9]* qmail-mysql-[0-9]* \
		qmail-spamcontrol-[0-9]* qmail-tls-[0-9]*

USE_OPENLDAP=	yes
SLAVE_LDAP=	yes

LDAP_PATCH_DATE=	20060201

MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr
PATCHDIR=	${.CURDIR}/files
LATEST_LINK=	${PORTNAME}-ldap

.include "${MASTERDIR}/Makefile"
