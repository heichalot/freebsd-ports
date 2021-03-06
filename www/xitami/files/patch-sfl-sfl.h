--- sfl/sfl.h.orig	Fri Jul 11 23:10:08 2003
+++ sfl/sfl.h	Tue Jul 20 15:21:33 2004
@@ -175,6 +175,10 @@
 #elif (defined (FreeBSD) || defined (__FreeBSD__))
 #   define __UTYPE_FREEBSD
 #   define __UNIX__
+#if !defined(__i386__)
+#   undef  __IS_32BIT__
+#   define __IS_64BIT__
+#endif
 #elif (defined (NetBSD) || defined (__NetBSD__))
 #   define __UTYPE_NETBSD
 #   define __UNIX__
