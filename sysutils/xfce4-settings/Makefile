# New ports collection makefile for:	xfce4-settings
# Date created:		2 October 2008
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-settings
PORTVERSION=	4.6.5
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 settings application

LIB_DEPENDS=	wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

OPTIONS=	XKLAVIER	"Keyboard layout settings"		off \
		XCURSOR		"Enable cursor themes support"		on \
		XRANDR		"Enable Xrandr support"			on \
		NOTIFY		"Enable notification support"		on \
		NLS		"Enable Native Language Support"	on

CONFIGURE_ARGS=	--disable-sound-settings --disable-debug
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget glib20 gtk20 desktopfileutils intltool intlhack \
		libglade2 pkgconfig
USE_XFCE=	configenv libexo libgui libutil xfconf
USE_XORG=	x11 xi

.include <bsd.port.pre.mk>

.if defined(WITH_XKLAVIER)
LIB_DEPENDS+=	xklavier.12:${PORTSDIR}/x11/libxklavier
CONFIGURE_ARGS+=--enable-libxklavier
.else
CONFIGURE_ARGS+=--disable-libxklavier
.endif

.if defined(WITH_XCURSOR)
USE_XORG+=	xcursor
CONFIGURE_ARGS+=--enable-xcursor
.else
CONFIGURE_ARGS+=--disable-xcursor
.endif

.if defined(WITH_XRANDR)
USE_XORG+=	xrandr
CONFIGURE_ARGS+=--enable-xrandr
PLIST_SUB+=	XRANDR=""
.else
CONFIGURE_ARGS+=--disable-xrandr
PLIST_SUB+=	XRANDR="@comment "
.endif

.if defined(WITH_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	# until xfce4-icon-theme is back we rely on Tango
	@${REINPLACE_CMD} -e 's|Rodent|Tango|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c \
		${WRKSRC}/xfsettingsd/xsettings.xml
	@${REINPLACE_CMD} -e 's|xkl_config_registry_load (settings->priv->xkl_registry)|xkl_config_registry_load (settings->priv->xkl_registry, FALSE)|g; \
		s|xkl_engine_stop_listen (settings->priv->xkl_engine)|xkl_engine_stop_listen (settings->priv->xkl_engine, FALSE)|g' \
		${WRKSRC}/dialogs/keyboard-settings/xfce-keyboard-settings.c

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
