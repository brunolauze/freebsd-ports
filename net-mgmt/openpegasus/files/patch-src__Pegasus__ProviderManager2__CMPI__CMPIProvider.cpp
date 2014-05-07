--- src/Pegasus/ProviderManager2/CMPI/CMPIProvider.cpp.orig	2014-02-25 16:54:40.078424160 -0600
+++ src/Pegasus/ProviderManager2/CMPI/CMPIProvider.cpp	2014-02-25 16:55:41.754628677 -0600
@@ -361,7 +361,7 @@
                    hopefully fix that.
                 */
 #if !defined(PEGASUS_DEBUG)
-# if defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU)
+# if defined(PEGASUS_PLATFORM_LINUX_GENERIC_GNU) || defined(PEGASUS_PLATFORM_FREEBSD_GENERIC_GNU)
                 Logger::put(Logger::STANDARD_LOG, System::CIMSERVER,
                     Logger::WARNING,
                     "Provider thread in $0 did not exit after cleanup function."
