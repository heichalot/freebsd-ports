--- src/main.c.orig	Mon May  5 06:05:32 2003
+++ src/main.c	Mon Jun  2 11:16:57 2003
@@ -73,6 +73,6 @@
 #endif
 
-extern char origbotname[], userfile[], botnetnick[];
+extern char origbotname[], userfile[], botnetnick[], tempdir[];
 extern int dcc_total, conmask, cache_hit, cache_miss, max_logs, quick_logs;
 extern struct dcc_t *dcc;
 extern struct userrec *userlist;
@@ -102,7 +102,7 @@
 int term_z = 0;         /* Foreground: use the terminal as a partyline?  */
 int use_stderr = 1;     /* Send stuff to stderr instead of logfiles?     */
 
-char configfile[121] = "eggdrop.conf";  /* Default config file name */
+char configfile[121] = __PREFIX__ "/etc/eggdrop.conf";  /* Default config file name */
 char pid_file[120];                     /* Name of the pid file     */
 char helpdir[121] = "help/";            /* Directory of help files  */
 char textdir[121] = "text/";            /* Directory for text files */
@@ -732,6 +732,8 @@
   }
 #endif
 
+  chdir(__PREFIX__ "/share/eggdrop");
+
   /* Initialise context list */
   for (i = 0; i < 16; i++)
     Context;
@@ -831,7 +833,7 @@
   cache_miss = 0;
   cache_hit = 0;
   if (!pid_file[0])
-    egg_snprintf(pid_file, sizeof pid_file, "pid.%s", botnetnick);
+    egg_snprintf(pid_file, sizeof pid_file, "%.100s/pid.%.32s", tempdir, botnetnick);
 
   /* Check for pre-existing eggdrop! */
   f = fopen(pid_file, "r");
