--- src/kmk/kmkbuiltin.h.orig	2013-12-22 21:48:47.536038054 -0600
+++ src/kmk/kmkbuiltin.h	2013-12-22 21:52:31.513437843 -0600
@@ -50,7 +50,7 @@
 extern int kmk_builtin_rm(int argc, char **argv, char **envp);
 extern int kmk_builtin_rmdir(int argc, char **argv, char **envp);
 extern int kmk_builtin_sleep(int argc, char **argv, char **envp);
-extern int kmk_builtin_test(int argc, char **argv, char **envp, char ***ppapszArgvSpawn);
+extern int kmk_builtin_test(int argc, char **argv, char **envp);
 extern int kmk_builtin_kDepIDB(int argc, char **argv, char **envp);
 extern int kmk_builtin_kDepObj(int argc, char **argv, char **envp);
 
