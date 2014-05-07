--- src/WMIMapper/WMIServer/cimserver.cpp.orig	2014-02-28 16:40:43.197837588 -0600
+++ src/WMIMapper/WMIServer/cimserver.cpp	2014-02-28 16:42:23.202833298 -0600
@@ -714,6 +714,7 @@
     }
 
 #if defined(PEGASUS_OS_HPUX) || defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) \
+|| defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU) \
 || defined(PEGASUS_OS_ZOS) || defined(PEGASUS_OS_AIX) \
 || defined(PEGASUS_OS_SOLARIS) || defined (PEGASUS_OS_VMS)
     umask(S_IWGRP|S_IWOTH);
@@ -834,6 +835,7 @@
 
 #if defined(PEGASUS_OS_HPUX) || \
     defined(PEGASUS_OS_LINUX) || \
+    defined(PEGASUS_OS_FREEBSD) || \
     defined(PEGASUS_OS_ZOS) || \
     defined(PEGASUS_OS_AIX) || \
     defined(PEGASUS_OS_SOLARIS) || \
