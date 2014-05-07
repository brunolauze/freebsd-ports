--- src/Pegasus/Common/SystemUnix.cpp.orig	2014-02-28 20:46:23.061421957 -0600
+++ src/Pegasus/Common/SystemUnix.cpp	2014-02-28 20:46:51.158178674 -0600
@@ -30,7 +30,8 @@
 //%/////////////////////////////////////////////////////////////////////////////
 
 #if !defined(PEGASUS_OS_ZOS) && \
-    !defined(PEGASUS_OS_DARWIN)
+    !defined(PEGASUS_OS_DARWIN) && \
+    !defined(PEGASUS_OS_FREEBSD)
 # include <crypt.h>
 #endif
 
