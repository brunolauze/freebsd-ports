--- hotspot/src/share/vm/code/relocInfo.hpp.orig	2014-01-31 11:05:46.109716698 -0600
+++ hotspot/src/share/vm/code/relocInfo.hpp	2014-01-31 11:12:00.979415950 -0600
@@ -371,7 +371,7 @@
   // "immediate" in the prefix header word itself.  This optimization
   // is invisible outside this module.)
 
-  inline friend relocInfo prefix_relocInfo(int datalen = 0);
+  inline friend relocInfo prefix_relocInfo(int datalen);
 
  protected:
   // an immediate relocInfo optimizes a prefix with one 10-bit unsigned value
