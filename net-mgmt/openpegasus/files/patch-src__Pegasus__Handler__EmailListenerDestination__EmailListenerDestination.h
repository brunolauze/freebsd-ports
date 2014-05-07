--- src/Pegasus/Handler/EmailListenerDestination/EmailListenerDestination.h.orig	2008-12-16 12:56:44.000000000 -0600
+++ src/Pegasus/Handler/EmailListenerDestination/EmailListenerDestination.h	2014-04-23 11:29:47.495139503 -0500
@@ -34,7 +34,8 @@
 PEGASUS_USING_STD;
 
 #if defined(PEGASUS_OS_HPUX) || \
-    defined(PEGASUS_OS_LINUX)
+    defined(PEGASUS_OS_LINUX) || \
+    defined(PEGASUS_OS_FREEBSD)
 # define SENDMAIL_CMD "/usr/sbin/sendmail"
 # define SENDMAIL_CMD_OPTS "-t -i <"
 # define TEMP_MAIL_FILE "tmpMailFile"
