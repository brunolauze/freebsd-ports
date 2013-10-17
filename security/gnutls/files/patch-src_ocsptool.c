--- src/ocsptool.c.orig	2013-10-07 09:37:19.495757564 -0500
+++ src/ocsptool.c	2013-10-07 09:45:31.352380700 -0500
@@ -43,6 +43,21 @@
 static unsigned int encoding;
 unsigned int verbose = 0;
 
+
+static void error (int __status, int __errnum, const char *__format, const char *__stderr)
+{
+	char* res;
+	strcpy(res, __stderr);
+	if (__errnum != 0)
+        {
+		strcmp(res, ":");
+		strcmp(res, strerror(__errnum));
+	}
+	fprintf (res, __format);
+	if (__status != 0)
+		exit(__status);
+}
+
 static void
 tls_log_func (int level, const char *str)
 {
@@ -66,7 +81,7 @@
   else
     dat.data = (void*)fread_file (infile, &size);
   if (dat.data == NULL)
-    error (EXIT_FAILURE, errno, "reading request");
+    error (EXIT_FAILURE, errno, "reading request", "");
   dat.size = size;
 
   ret = gnutls_ocsp_req_import (req, &dat);
@@ -123,7 +138,7 @@
   else
     dat.data = (void*)fread_file (infile, &size);
   if (dat.data == NULL)
-    error (EXIT_FAILURE, errno, "reading response");
+    error (EXIT_FAILURE, errno, "reading response", "");
   dat.size = size;
 
   _response_info(&dat);
@@ -139,7 +154,7 @@
   size_t size;
 
   if (!HAVE_OPT(LOAD_ISSUER))
-    error (EXIT_FAILURE, 0, "missing --load-issuer");
+    error (EXIT_FAILURE, 0, "missing --load-issuer", "");
 
   ret = gnutls_x509_crt_init (&crt);
   if (ret < 0)
@@ -154,8 +169,7 @@
   ret = gnutls_x509_crt_import (crt, &dat, encoding);
   free (dat.data);
   if (ret < 0)
-    error (EXIT_FAILURE, 0, "importing --load-issuer: %s: %s",
-           OPT_ARG(LOAD_ISSUER), gnutls_strerror (ret));
+    error (EXIT_FAILURE, 0, "importing --load-issuer: %s", gnutls_strerror (ret));
 
   return crt;
 }
@@ -169,7 +183,7 @@
   size_t size;
 
   if (!HAVE_OPT(LOAD_CERT))
-    error (EXIT_FAILURE, 0, "missing --load-cert");
+    error (EXIT_FAILURE, 0, "missing --load-cert", "");
 
   ret = gnutls_x509_crt_init (&crt);
   if (ret < 0)
@@ -184,8 +198,8 @@
   ret = gnutls_x509_crt_import (crt, &dat, encoding);
   free (dat.data);
   if (ret < 0)
-    error (EXIT_FAILURE, 0, "importing --load-cert: %s: %s",
-           OPT_ARG(LOAD_CERT), gnutls_strerror (ret));
+    error (EXIT_FAILURE, 0, "importing --load-cert: %s",
+           gnutls_strerror (ret));
 
   return crt;
 }
@@ -289,8 +303,7 @@
       ret = gnutls_x509_crt_import (signer, &dat, encoding);
       free (dat.data);
       if (ret < 0)
-	error (EXIT_FAILURE, 0, "importing --load-signer: %s: %s",
-	       OPT_ARG(LOAD_SIGNER), gnutls_strerror (ret));
+	error (EXIT_FAILURE, 0, "importing --load-signer: %s", gnutls_strerror (ret));
 
       if (HAVE_OPT(VERBOSE))
 	{
@@ -312,7 +325,7 @@
 	       gnutls_strerror (ret));
     }
   else
-    error (EXIT_FAILURE, 0, "missing --load-trust or --load-signer");
+    error (EXIT_FAILURE, 0, "missing --load-trust or --load-signer", "");
 
   printf ("Verifying OCSP Response: ");
   print_ocsp_verify_res (verify);
@@ -334,7 +347,7 @@
   else
     dat.data = (void*)fread_file (infile, &size);
   if (dat.data == NULL)
-    error (EXIT_FAILURE, errno, "reading response");
+    error (EXIT_FAILURE, errno, "reading response", "");
   dat.size = size;
   
   _verify_response(&dat);
