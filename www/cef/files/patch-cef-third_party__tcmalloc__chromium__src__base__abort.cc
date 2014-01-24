--- third_party/tcmalloc/chromium/src/base/abort.cc.orig	2014-01-23 11:32:11.684257720 -0600
+++ third_party/tcmalloc/chromium/src/base/abort.cc	2014-01-23 11:32:44.723547318 -0600
@@ -12,7 +12,7 @@
 ATTRIBUTE_NOINLINE void Abort() {
   // Make a segmentation fault to force abort. Writing to a specific address
   // so it's easier to find on crash stacks.
-  *(reinterpret_cast<volatile char*>(NULL) + 57) = 0x21;
+  *(static_cast<volatile char*>(NULL) + 57) = 0x21;
 }
 
 } // namespace tcmalloc
