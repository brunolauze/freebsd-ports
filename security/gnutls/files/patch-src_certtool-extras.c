--- src/certtool-extras.c.orig	2013-10-07 10:39:08.988502351 -0500
+++ src/certtool-extras.c	2013-10-07 11:04:07.440396707 -0500
@@ -45,6 +45,22 @@
 
 #define MAX_KEYS 256
 
+
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
 /* Loads a x509 private key list
  */
 gnutls_x509_privkey_t *
@@ -64,7 +80,7 @@
   if (info->privkey == NULL)
     {
       if (mand)
-        error (EXIT_FAILURE, 0, "missing --load-privkey");
+        error (EXIT_FAILURE, 0, "missing --load-privkey", "");
       else
         return NULL;
     }
