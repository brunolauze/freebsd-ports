--- src/Pegasus/Config/FixedPropertyTable.h.orig	2014-02-25 15:22:53.515821506 -0600
+++ src/Pegasus/Config/FixedPropertyTable.h	2014-02-25 15:23:25.142874642 -0600
@@ -36,6 +36,8 @@
 
 #if defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU)
 #include "FixedPropertyTableLinux.h"
+#elif defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU)
+#include "FixedPropertyTableFreeBSD.h"
 #elif defined(PEGASUS_OS_SOLARIS)
 # include "FixedPropertyTableSolaris.h"
 #elif PEGASUS_PLATFORM_HPUX_ACC
