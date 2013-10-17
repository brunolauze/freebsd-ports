--- src/gallium/include/pipe/p_config.h.orig	2013-10-07 13:11:22.625870027 -0500
+++ src/gallium/include/pipe/p_config.h	2013-10-07 13:12:57.582864403 -0500
@@ -122,6 +122,15 @@
 #define PIPE_ARCH_AARCH64
 #endif
 
+#if defined(__sparc__) || defined(__sparc64__)
+#define PIPE_ARCH_SPARC
+#if defined(__sparc64__)
+#define PIPE_ARCH_SPARC_64
+#endif
+#endif
+
+
+
 /*
  * Endian detection.
  */
@@ -157,7 +166,7 @@
 
 #if defined(PIPE_ARCH_X86) || defined(PIPE_ARCH_X86_64) || defined(PIPE_ARCH_ARM) || defined(PIPE_ARCH_AARCH64)
 #define PIPE_ARCH_LITTLE_ENDIAN
-#elif defined(PIPE_ARCH_PPC) || defined(PIPE_ARCH_PPC_64) || defined(PIPE_ARCH_S390)
+#elif defined(PIPE_ARCH_PPC) || defined(PIPE_ARCH_PPC_64) || defined(PIPE_ARCH_S390) || defined(PIPE_ARCH_SPARC) || defined(PIPE_ARCH_SPARC_64)
 #define PIPE_ARCH_BIG_ENDIAN
 #endif
 
