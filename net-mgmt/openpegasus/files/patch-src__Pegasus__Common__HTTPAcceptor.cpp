--- src/Pegasus/Common/HTTPAcceptor.cpp.orig	2014-02-25 14:34:55.674035577 -0600
+++ src/Pegasus/Common/HTTPAcceptor.cpp	2014-02-25 14:35:53.609000026 -0600
@@ -510,6 +510,7 @@
     //
 #if !defined(PEGASUS_DISABLE_LOCAL_DOMAIN_SOCKET) && \
      (defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) || \
+      defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU) || \
       defined(PEGASUS_OS_ZOS) || \
       defined(PEGASUS_OS_PASE))
     if (_connectionType == LOCAL_CONNECTION)
