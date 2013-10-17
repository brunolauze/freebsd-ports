--- src/certtool-common.c.orig	2013-10-07 10:08:01.118630141 -0500
+++ src/certtool-common.c	2013-10-07 10:17:19.311986713 -0500
@@ -50,6 +50,20 @@
 const int buffer_size = sizeof (buffer);
 
 
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
 FILE *
 safe_open_rw (const char *file, int privkey_op)
 {
@@ -86,7 +100,7 @@
   if (info->secret_key == NULL)
     {
       if (mand)
-        error (EXIT_FAILURE, 0, "missing --secret-key");
+        error (EXIT_FAILURE, 0, "missing --secret-key", "");
       else
         return NULL;
     }
@@ -147,13 +161,13 @@
   if (ret == GNUTLS_E_BASE64_UNEXPECTED_HEADER_ERROR)
     {
       error (EXIT_FAILURE, 0,
-             "import error: could not find a valid PEM header; "
+             "import error: could not find a valid PEM header; %s",
              "check if your key is PKCS #12 encoded");
     }
 
   if (ret < 0)
-    error (EXIT_FAILURE, 0, "importing --load-privkey: %s: %s",
-           info->privkey, gnutls_strerror (ret));
+    error (EXIT_FAILURE, 0, "importing --load-privkey: %s",
+            gnutls_strerror (ret));
 
   return key;
 }
@@ -169,8 +183,8 @@
 
   ret = gnutls_privkey_import_url(key, url, 0);
   if (ret < 0)
-    error (EXIT_FAILURE, 0, "importing key: %s: %s",
-           url, gnutls_strerror (ret));
+    error (EXIT_FAILURE, 0, "importing key: %s",
+            gnutls_strerror (ret));
 
   return key;
 }
@@ -184,7 +198,7 @@
   ret = gnutls_pubkey_init (&pubkey);
   if (ret < 0)
     {
-      fprintf (stderr, "Error in %s:%d: %s\n", __func__, __LINE__,
+      fprintf (stderr, "Error in %s\n",
                gnutls_strerror (ret));
       exit (1);
     }
@@ -192,8 +206,8 @@
   ret = gnutls_pubkey_import_url (pubkey, url, obj_flags);
   if (ret < 0)
     {
-      fprintf (stderr, "Error in %s:%d: %s: %s\n", __func__, __LINE__,
-               gnutls_strerror (ret), url);
+      fprintf (stderr, "Error in %s\n",
+               gnutls_strerror (ret));
       exit (1);
     }
 
@@ -214,7 +228,7 @@
     return NULL;
 
   if (info->privkey == NULL)
-    error (EXIT_FAILURE, 0, "missing --load-privkey");
+    error (EXIT_FAILURE, 0, "missing --load-privkey", "");
 
   if (gnutls_url_is_supported(info->privkey) != 0)
     return _load_url_privkey(info->privkey);
@@ -249,7 +263,7 @@
     return NULL;
 
   if (info->privkey == NULL)
-    error (EXIT_FAILURE, 0, "missing --load-privkey");
+    error (EXIT_FAILURE, 0, "missing --load-privkey", "");
 
   ret = gnutls_x509_privkey_init (&key);
   if (ret < 0)
@@ -283,13 +297,13 @@
   if (ret == GNUTLS_E_BASE64_UNEXPECTED_HEADER_ERROR)
     {
       error (EXIT_FAILURE, 0,
-             "import error: could not find a valid PEM header; "
+             "import error: could not find a valid PEM header; %s",
              "check if your key is PKCS #12 encoded");
     }
 
   if (ret < 0)
-    error (EXIT_FAILURE, 0, "importing --load-privkey: %s: %s",
-           info->privkey, gnutls_strerror (ret));
+    error (EXIT_FAILURE, 0, "importing --load-privkey: %s",
+           gnutls_strerror (ret));
 
   return key;
 }
@@ -332,7 +346,7 @@
   if (info->cert == NULL)
     {
       if (mand)
-        error (EXIT_FAILURE, 0, "missing --load-certificate");
+        error (EXIT_FAILURE, 0, "missing --load-certificate", "");
       else
         return NULL;
     }
@@ -411,13 +425,13 @@
   if (ret == GNUTLS_E_BASE64_UNEXPECTED_HEADER_ERROR)
     {
       error (EXIT_FAILURE, 0,
-             "import error: could not find a valid PEM header");
+             "import error: could not find a valid PEM header", "");
     }
 
   free (dat.data);
   if (ret < 0)
-    error (EXIT_FAILURE, 0, "importing --load-request: %s: %s",
-           info->request, gnutls_strerror (ret));
+    error (EXIT_FAILURE, 0, "importing --load-request: %s",
+            gnutls_strerror (ret));
 
   return crq;
 }
@@ -432,7 +446,7 @@
   size_t size;
 
   if (info->ca_privkey == NULL)
-    error (EXIT_FAILURE, 0, "missing --load-ca-privkey");
+    error (EXIT_FAILURE, 0, "missing --load-ca-privkey", "");
 
   if (gnutls_url_is_supported(info->ca_privkey) != 0)
     return _load_url_privkey(info->ca_privkey);
@@ -462,7 +476,7 @@
   size_t size;
 
   if (info->ca == NULL)
-    error (EXIT_FAILURE, 0, "missing --load-ca-certificate");
+    error (EXIT_FAILURE, 0, "missing --load-ca-certificate", "");
 
   ret = gnutls_x509_crt_init (&crt);
   if (ret < 0)
@@ -478,8 +492,8 @@
   ret = gnutls_x509_crt_import (crt, &dat, info->incert_format);
   free (dat.data);
   if (ret < 0)
-    error (EXIT_FAILURE, 0, "importing --load-ca-certificate: %s: %s",
-           info->ca, gnutls_strerror (ret));
+    error (EXIT_FAILURE, 0, "importing --load-ca-certificate: %s",
+           gnutls_strerror (ret));
 
   return crt;
 }
@@ -499,7 +513,7 @@
     return NULL;
 
   if (info->pubkey == NULL)
-    error (EXIT_FAILURE, 0, "missing --load-pubkey");
+    error (EXIT_FAILURE, 0, "missing --load-pubkey", "");
 
   if (gnutls_url_is_supported(info->pubkey) != 0)
     return _load_url_pubkey(info->pubkey);
@@ -521,13 +535,13 @@
   if (ret == GNUTLS_E_BASE64_UNEXPECTED_HEADER_ERROR)
     {
       error (EXIT_FAILURE, 0,
-             "import error: could not find a valid PEM header; "
+             "import error: could not find a valid PEM header; %s",
              "check if your key has the PUBLIC KEY header");
     }
 
   if (ret < 0)
-    error (EXIT_FAILURE, 0, "importing --load-pubkey: %s: %s",
-           info->pubkey, gnutls_strerror (ret));
+    error (EXIT_FAILURE, 0, "importing --load-pubkey: %s",
+           gnutls_strerror (ret));
 
   return key;
 }
