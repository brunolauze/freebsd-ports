--- src/Pegasus/Config/DefaultPropertyTable.h.orig	2014-02-25 15:18:02.081865800 -0600
+++ src/Pegasus/Config/DefaultPropertyTable.h	2014-02-25 15:23:43.655803231 -0600
@@ -50,6 +50,8 @@
 
 #if defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU)
 # include "DefaultPropertyTableLinux.h"
+#elif defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU)
+# include "DefaultPropertyTableFreeBSD.h"
 #elif defined(PEGASUS_OS_SOLARIS)
 # include "DefaultPropertyTableSolaris.h"
 #elif PEGASUS_PLATFORM_HPUX_ACC
