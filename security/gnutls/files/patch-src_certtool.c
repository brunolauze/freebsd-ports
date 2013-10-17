--- src/certtool.c.orig	2013-10-07 11:04:47.794393051 -0500
+++ src/certtool.c	2013-10-07 11:30:25.315286661 -0500
@@ -83,6 +83,19 @@
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
@@ -1124,8 +1137,9 @@
                                  GNUTLS_X509_CRT_LIST_IMPORT_FAIL_IF_EXCEED);
   if (ret == GNUTLS_E_SHORT_MEMORY_BUFFER)
     {
+      char crt_num_str = (char)crt_num;
       error (0, 0, "too many certificates (%d); "
-             "will only read the first %d", crt_num, MAX_CRTS);
+             "will only read the first 256", &crt_num_str);
       crt_num = MAX_CRTS;
       ret = gnutls_x509_crt_list_import (crt, &crt_num, &pem,
                                          incert_format, 0);
@@ -1139,7 +1153,7 @@
 
   if (count > 1 && outcert_format == GNUTLS_X509_FMT_DER)
     {
-      error (0, 0, "cannot output multiple certificates in DER format; "
+      error (0, 0, "cannot output multiple certificates in DER format; ",
              "using PEM instead");
       outcert_format = GNUTLS_X509_FMT_PEM;
     }
@@ -2140,7 +2154,7 @@
 
   buf = (void*)fread_file (infile, &size);
   if (buf == NULL)
-    error (EXIT_FAILURE, errno, "reading chain");
+    error (EXIT_FAILURE, errno, "reading chain", "");
 
   buf[size] = 0;
 
@@ -2157,17 +2171,17 @@
   FILE * ca_file = fopen(cinfo->ca, "r");
   
   if (ca_file == NULL)
-    error (EXIT_FAILURE, errno, "opening CA file");
+    error (EXIT_FAILURE, errno, "opening CA file", "");
 
   cert = (void*)fread_file (infile, &cert_size);
   if (cert == NULL)
-    error (EXIT_FAILURE, errno, "reading certificate chain");
+    error (EXIT_FAILURE, errno, "reading certificate chain", "");
 
   cert[cert_size] = 0;
 
   cas = (void*)fread_file (ca_file, &ca_size);
   if (cas == NULL)
-    error (EXIT_FAILURE, errno, "reading CA list");
+    error (EXIT_FAILURE, errno, "reading CA list", "");
 
   cas[ca_size] = 0;
   fclose(ca_file);
@@ -2317,7 +2331,7 @@
 
       result = gnutls_pkcs12_bag_set_crt (bag, crts[i]);
       if (result < 0)
-        error (EXIT_FAILURE, 0, "set_crt[%d]: %s", i,
+        error (EXIT_FAILURE, 0, "set_crt[0]: %s",
                gnutls_strerror (result));
 
       indx = result;
@@ -2333,7 +2347,7 @@
       size = sizeof (_key_id);
       result = gnutls_x509_crt_get_key_id (crts[i], 0, _key_id, &size);
       if (result < 0)
-        error (EXIT_FAILURE, 0, "key_id[%d]: %s", i,
+        error (EXIT_FAILURE, 0, "key_id[0]: %s", 
                gnutls_strerror (result));
 
       key_id.data = _key_id;
@@ -2366,7 +2380,7 @@
         gnutls_x509_privkey_export_pkcs8 (keys[i], GNUTLS_X509_FMT_DER,
                                           pass, flags, buffer, &size);
       if (result < 0)
-        error (EXIT_FAILURE, 0, "key_export[%d]: %s", i, gnutls_strerror (result));
+        error (EXIT_FAILURE, 0, "key_export[%d]: %s", gnutls_strerror (result));
 
       data.data = buffer;
       data.size = size;
@@ -2386,7 +2400,7 @@
       size = sizeof (_key_id);
       result = gnutls_x509_privkey_get_key_id (keys[i], 0, _key_id, &size);
       if (result < 0)
-        error (EXIT_FAILURE, 0, "key_id[%d]: %s", i, gnutls_strerror (result));
+        error (EXIT_FAILURE, 0, "key_id[0]: %s", gnutls_strerror (result));
 
       key_id.data = _key_id;
       key_id.size = size;
@@ -2590,7 +2604,7 @@
     }
 
   if (fail)
-    error (EXIT_FAILURE, 0, "There were errors parsing the structure\n");
+    error (EXIT_FAILURE, 0, "There were errors parsing the structure\n", "");
 }
 
 void
@@ -2690,7 +2704,7 @@
     {
       len = getline (&lineptr, &linesize, infile);
       if (len == -1)
-        error (EXIT_FAILURE, 0, "cannot find RFC 2822 header/body separator");
+        error (EXIT_FAILURE, 0, "cannot find RFC 2822 header/body separator", "");
     }
   while (strcmp (lineptr, "\r\n") != 0 && strcmp (lineptr, "\n") != 0);
 
@@ -2698,7 +2712,7 @@
     {
       len = getline (&lineptr, &linesize, infile);
       if (len == -1)
-        error (EXIT_FAILURE, 0, "message has RFC 2822 header but no body");
+        error (EXIT_FAILURE, 0, "message has RFC 2822 header but no body", "");
     }
   while (strcmp (lineptr, "\r\n") == 0 && strcmp (lineptr, "\n") == 0);
 
