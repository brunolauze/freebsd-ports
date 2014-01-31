https://bugs.openjdk.java.net/browse/JDK-7191817

--- hotspot/src/share/vm/runtime/arguments.cpp
+++ hotspot/src/share/vm/runtime/arguments.cpp
@@ -2549,7 +2549,9 @@
          FLAG_SET_CMDLINE(uintx, MaxNewSize, NewSize);
       }
 
+#ifndef _ALLBSD_SOURCE  // UseLargePages is not yet supported on BSD.
       FLAG_SET_DEFAULT(UseLargePages, true);
+#endif
 
       // Increase some data structure sizes for efficiency
       FLAG_SET_CMDLINE(uintx, BaseFootPrintEstimate, MaxHeapSize);
@@ -3111,6 +3113,10 @@
   UNSUPPORTED_OPTION(UseG1GC, "G1 GC");
 #endif
 
+#ifdef _ALLBSD_SOURCE  // UseLargePages is not yet supported on BSD.
+  UNSUPPORTED_OPTION(UseLargePages, "-XX:+UseLargePages");
+#endif
+
 #ifndef PRODUCT
   if (TraceBytecodesAt != 0) {
     TraceBytecodes = true;
