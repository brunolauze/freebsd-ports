--- breakpad/breakpad.gyp.orig	2014-01-16 20:15:23.406618683 -0600
+++ breakpad/breakpad.gyp	2014-01-16 20:16:08.346279958 -0600
@@ -340,7 +340,7 @@
         },
       ],
     }],
-    [ 'OS=="linux" or OS=="android"', {
+    [ 'OS=="linux" or os_bsd == 1 or OS=="android"', {
       'conditions': [
         ['OS=="android"', {
           'defines': [
