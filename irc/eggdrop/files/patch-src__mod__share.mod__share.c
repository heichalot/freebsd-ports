--- src/mod/share.mod/share.c.orig	Mon May  5 00:05:33 2003
+++ src/mod/share.mod/share.c	Tue Nov 18 16:51:41 2003
@@ -1120,7 +1120,7 @@
   int i, sock;
   FILE *f;
 
-  egg_snprintf(s, sizeof s, ".share.%s.%li.users", botnetnick, now);
+  egg_snprintf(s, sizeof s, "%.100s/.share.%.32s.%lu.users", tempdir, botnetnick, now);
   if (!(b_status(idx) & STAT_SHARE)) {
     dprintf(idx, "s e You didn't ask; you just started sending.\n");
     dprintf(idx, "s e Ask before sending the userfile.\n");
@@ -1889,8 +1889,8 @@
   struct chanuserrec *ch;
   struct chanset_t *cst;
 
-  egg_snprintf(share_file, sizeof share_file, ".share.%s.%lu", dcc[idx].nick,
-               now);
+  egg_snprintf(share_file, sizeof share_file, "%.100s/.share.%s.%lu",
+		  tempdir, dcc[idx].nick, now);
   if (dcc[idx].u.bot->uff_flags & UFF_OVERRIDE) {
     debug1("NOTE: Sharing aggressively with %s, overriding its local bots.",
            dcc[idx].nick);
