--- src/danetool.c.orig	2013-10-07 11:18:03.387338277 -0500
+++ src/danetool.c	2013-10-07 11:18:39.189004654 -0500
@@ -65,6 +65,19 @@
  */
 int batch;
 
+static void error (int __status, int __errnum, const char *__format, const char *__stderr)
+{
+        char* res;
+        strcpy(res, __stderr);
+        if (__errnum != 0)
+        {
+                strcmp(res, ":");
+                strcmp(res, strerror(__errnum));
+        }
+        fprintf (res, __format);
+        if (__status != 0)
+                exit(__status);
+}
 
 static void
 tls_log_func (int level, const char *str)
