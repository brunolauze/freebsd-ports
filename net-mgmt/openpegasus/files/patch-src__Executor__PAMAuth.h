--- src/Executor/PAMAuth.h.orig	2014-02-28 16:33:46.003929183 -0600
+++ src/Executor/PAMAuth.h	2014-02-28 16:36:27.796404022 -0600
@@ -304,7 +304,7 @@
 
 static int PAMAuthenticateCallback(
     int num_msg,
-#if defined(PEGASUS_OS_LINUX)
+#if defined(PEGASUS_OS_LINUX) || defined(PEGASUS_OS_FREEBSD)
     const struct pam_message** msg,
 #else
     struct pam_message** msg,
@@ -358,7 +358,7 @@
 
 static int PAMValidateUserCallback(
     int num_msg,
-#if defined(PEGASUS_OS_LINUX)
+#if defined(PEGASUS_OS_LINUX) || defined(PEGASUS_OS_FREEBSD)
     const struct pam_message** msg,
 #else
     struct pam_message** msg,
