--- src/gtk/MainView.cxx.orig	2009-03-01 05:00:55.000000000 +0800
+++ src/gtk/MainView.cxx	2009-03-28 12:18:20.000000000 +0800
@@ -77,7 +77,7 @@
 static void main_window_zoom_out_cb (GtkWidget *, gpointer);
 static void main_window_zoom_width_cb (GtkToggleAction *, gpointer);
 static void main_window_set_page_mode (GtkRadioAction *, GtkRadioAction *, gpointer);
-static void main_window_page_scrolled_cb (GtkWidget *widget, GdkEventScroll *event, gpointer data);
+static gboolean main_window_page_scrolled_cb (GtkWidget *widget, GdkEventScroll *event, gpointer data);
 
 #if defined (HAVE_CUPS)
 static void main_window_print_cb (GtkWidget *, gpointer);
@@ -1479,18 +1479,19 @@
     pter->setPageMode (mode);
 }
 
-void 
+gboolean
 main_window_page_scrolled_cb (GtkWidget *widget, GdkEventScroll *event, gpointer data)
 {
     g_assert ( NULL != data && "The data parameter is NULL.");
 
     MainPter *pter = (MainPter *)data;
     // Only zoom when the CTRL-Button is down...
-    if ( !(event->state & GDK_CONTROL_MASK) ) return;
+    if ( !(event->state & GDK_CONTROL_MASK) ) return FALSE;
     if ( event->direction == GDK_SCROLL_UP ) {
         pter->zoomInActivated ();
     } else if ( event->direction == GDK_SCROLL_DOWN ) {
         pter->zoomOutActivated ();
     }
+    return TRUE;
 }
 
