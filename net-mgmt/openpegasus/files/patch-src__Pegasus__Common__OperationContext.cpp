--- src/Pegasus/Common/OperationContext.cpp.orig	2014-02-25 14:33:17.735974868 -0600
+++ src/Pegasus/Common/OperationContext.cpp	2014-02-25 14:33:49.834071444 -0600
@@ -34,6 +34,7 @@
 #include <Pegasus/Common/MessageLoader.h>
 
 #if defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) || \
+    defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU) || \
     defined(PEGASUS_PLATFORM_DARWIN_PPC_GNU) || \
     defined(PEGASUS_PLATFORM_DARWIN_IX86_GNU)
 # define PEGASUS_INCLUDE_SUPERCLASS_INITIALIZER
