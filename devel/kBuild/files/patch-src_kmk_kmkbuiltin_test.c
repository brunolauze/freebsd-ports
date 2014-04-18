--- src/kmk/kmkbuiltin/test.c.orig	2013-12-23 07:55:32.642624197 -0600
+++ src/kmk/kmkbuiltin/test.c	2013-12-23 07:56:20.564099361 -0600
@@ -201,7 +201,7 @@
 }
 #endif
 
-int kmk_builtin_test(int argc, char **argv, char **envp, char ***ppapszArgvSpawn)
+int kmk_builtin_test(int argc, char **argv, char **envp)
 {
 	int res;
 	char **argv_spawn;
@@ -291,7 +291,6 @@
 			}
 			argv_new[i] = NULL;
 
-			*ppapszArgvSpawn = argv_new;
 			res = 0;
 #endif /* in kmk */
 		}
