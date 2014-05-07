--- src/Pegasus/Handler/EmailListenerDestination/EmailListenerDestination.cpp.orig	2014-04-23 11:27:23.662149766 -0500
+++ src/Pegasus/Handler/EmailListenerDestination/EmailListenerDestination.cpp	2014-04-23 11:29:09.018142125 -0500
@@ -56,7 +56,7 @@
 #endif
 
 #if !defined(PEGASUS_OS_HPUX) && !defined(PEGASUS_OS_LINUX) && \
-    !defined(PEGASUS_OS_VMS)
+    !defined(PEGASUS_OS_FREEBSD) && !defined(PEGASUS_OS_VMS)
 #error "Unsupported Platform"
 #endif
 
@@ -172,7 +172,7 @@
         "EmailListenerDestination::_sendViaEmail");
 
 #if defined(PEGASUS_OS_HPUX) || defined(PEGASUS_OS_LINUX) || \
-    defined(PEGASUS_OS_VMS)
+    defined(PEGASUS_OS_FREEBSD) || defined(PEGASUS_OS_VMS)
 
     String exceptionStr;
     FILE* filePtr;
