--- src/utils/stream.c.orig	2009-06-23 04:04:56.000000000 -0400
+++ src/utils/stream.c	2009-06-23 04:21:12.000000000 -0400
@@ -329,6 +329,7 @@
 
   /* o.k. */
   *ar = data;
+  fclose(fp);
   return n_data;
 
   /* ------------------------------------------------------- */
