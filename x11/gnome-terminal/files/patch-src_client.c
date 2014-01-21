--- src/client.c.orig	2014-01-20 21:17:01.438016219 -0600
+++ src/client.c	2014-01-20 21:17:47.498315830 -0600
@@ -524,7 +524,7 @@
      * because we want to use the value from PWD (if it is correct).
      * See bug 502146.
      */
-    cwd = get_current_dir_name ();
+    cwd = getcwd (NULL, 0);
     data->working_directory = g_strdup (cwd);
     free (cwd);
   }
