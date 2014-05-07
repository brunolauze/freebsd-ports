--- src/Pegasus/Common/OperationContextInternal.cpp.orig	2014-02-25 14:38:38.539219777 -0600
+++ src/Pegasus/Common/OperationContextInternal.cpp	2014-02-25 14:39:05.417128699 -0600
@@ -32,6 +32,7 @@
 #include "OperationContextInternal.h"
 
 #if defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) || \
+    defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU) || \
     defined(PEGASUS_PLATFORM_DARWIN_PPC_GNU) || \
     defined(PEGASUS_PLATFORM_DARWIN_IX86_GNU)
 # define PEGASUS_INCLUDE_SUPERCLASS_INITIALIZER
