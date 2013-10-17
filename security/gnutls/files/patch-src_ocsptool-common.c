--- src/ocsptool-common.c.orig	2013-10-07 09:47:24.365713681 -0500
+++ src/ocsptool-common.c	2013-10-07 09:48:25.690735335 -0500
@@ -46,6 +46,22 @@
   "Connection: close\r\n\r\n"
 static char buffer[MAX_BUF + 1];
 
+
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
+
+
 /* returns the host part of a URL */
 static const char* host_from_url(const char* url, unsigned int* port)
 {
