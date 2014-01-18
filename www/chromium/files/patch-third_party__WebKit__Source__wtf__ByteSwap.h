--- third_party/WebKit/Source/wtf/ByteSwap.h.orig	2014-01-17 01:05:46.235891585 -0600
+++ third_party/WebKit/Source/wtf/ByteSwap.h	2014-01-17 17:58:03.185300821 -0600
@@ -51,7 +51,7 @@
 ALWAYS_INLINE uint16_t bswap16(uint16_t x) { return _byteswap_ushort(x); }
 
 #else
-
+#ifndef __FreeBSD__
 ALWAYS_INLINE uint64_t bswap64(uint64_t x) { return __builtin_bswap64(x); }
 ALWAYS_INLINE uint32_t bswap32(uint32_t x) { return __builtin_bswap32(x); }
 // GCC 4.6 lacks __builtin_bswap16. Newer versions have it but we support 4.6.
@@ -60,7 +60,7 @@
 #else
 inline uint16_t bswap16(uint16_t x) { return ((x & 0xff00) >> 8) | ((x & 0x00ff) << 8); }
 #endif
-
+#endif
 #endif
 
 #if CPU(64BIT)
