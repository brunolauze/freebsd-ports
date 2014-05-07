--- src/Pegasus/Common/Config.h.orig	2014-02-28 20:05:21.257515450 -0600
+++ src/Pegasus/Common/Config.h	2014-02-28 20:07:45.696425688 -0600
@@ -104,6 +104,22 @@
 # include <Pegasus/Common/Platform_LINUX_IX86_CLANG.h>
 #elif defined (PEGASUS_PLATFORM_LINUX_SH4_GNU)
 # include <Pegasus/Common/Platform_LINUX_SH4_GNU.h>
+#elif defined (PEGASUS_PLATFORM_FREEBSD_AARCH64_GNU)
+# include <Pegasus/Common/Platform_FREEBSD_AARCH64_GNU.h>
+#elif defined (PEGASUS_PLATFORM_FREEBSD_X86_64_CLANG)
+# include <Pegasus/Common/Platform_FREEBSD_X86_64_CLANG.h>
+#elif defined (PEGASUS_PLATFORM_FREEBSD_IX86_CLANG)
+# include <Pegasus/Common/Platform_FREEBSD_IX86_CLANG.h>
+#elif defined (PEGASUS_PLATFORM_FREEBSD_SH4_GNU)
+# include <Pegasus/Common/Platform_FREEBSD_SH4_GNU.h>
+#elif defined (PEGASUS_PLATFORM_FREEBSD_IA64_GNU)
+# include <Pegasus/Common/Platform_FREEBSD_IA64_GNU.h>
+#elif defined (PEGASUS_PLATFORM_FREEBSD_X86_64_GNU)
+# include <Pegasus/Common/Platform_FREEBSD_X86_64_GNU.h>
+#elif defined (PEGASUS_PLATFORM_FREEBSD_PPC_GNU)
+# include <Pegasus/Common/Platform_FREEBSD_PPC_GNU.h>
+#elif defined (PEGASUS_PLATFORM_FREEBSD_PPC64_GNU)
+# include <Pegasus/Common/Platform_FREEBSD_PPC64_GNU.h>
 #else
 # error "<Pegasus/Common/Config.h>: Unsupported Platform"
 #endif
