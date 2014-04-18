--- src/kmk/kmkbuiltin.c.orig	2013-12-22 21:56:28.133529517 -0600
+++ src/kmk/kmkbuiltin.c	2013-12-22 21:56:49.663607713 -0600
@@ -208,7 +208,7 @@
     else if (!strcmp(pszCmd, "rmdir"))
         rc = kmk_builtin_rmdir(argc, argv, environ);
     else if (!strcmp(pszCmd, "test"))
-        rc = kmk_builtin_test(argc, argv, environ, ppapszArgvToSpawn);
+        rc = kmk_builtin_test(argc, argv, environ);
     /* rarely used commands: */
     else if (!strcmp(pszCmd, "kDepObj"))
         rc = kmk_builtin_kDepObj(argc, argv, environ);
