--- src/terminal.c.orig	2014-01-20 21:17:55.008299627 -0600
+++ src/terminal.c	2014-01-20 21:18:26.278237405 -0600
@@ -233,7 +233,7 @@
    * because we want to use the value from PWD (if it is correct).
    * See bug 502146.
    */
-  cwd = get_current_dir_name ();
+  cwd = getcwd (NULL, 0);
   working_directory = g_strdup (cwd);
   free (cwd);
 
