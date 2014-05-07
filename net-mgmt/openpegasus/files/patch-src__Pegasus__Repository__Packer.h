--- src/Pegasus/Repository/Packer.h.orig	2014-02-25 15:48:30.696867384 -0600
+++ src/Pegasus/Repository/Packer.h	2014-02-25 15:52:08.127674530 -0600
@@ -118,9 +118,9 @@
 
 inline bool Packer::isLittleEndian()
 {
-#if defined(PEGASUS_PLATFORM_LINUX_IA64_GNU)
+#if defined(PEGASUS_PLATFORM_LINUX_IA64_GNU) || defined(PEGASUS_PLATFORM_FREEBSD_IA64_GNU)
     return true;
-#elif defined(PEGASUS_PLATFORM_LINUX_X86_GNU)
+#elif defined(PEGASUS_PLATFORM_LINUX_X86_GNU) || defined(PEGASUS_PLATFORM_LINUX_X86_GNU)
     return true;
 #elif defined(PEGASUS_OS_ZOS)
     return false;
