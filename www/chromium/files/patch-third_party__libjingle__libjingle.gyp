--- third_party/libjingle/libjingle.gyp.orig	2014-01-13 09:00:02.000000000 -0600
+++ third_party/libjingle/libjingle.gyp	2014-01-14 23:51:12.535061768 -0600
@@ -541,7 +541,7 @@
             '<(libjingle_source)/talk/base/unixfilesystem.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'sources': [
             '<(libjingle_source)/talk/base/latebindingsymboltable.cc',
             '<(libjingle_source)/talk/base/latebindingsymboltable.h',
