--- skia/skia_common.gypi.orig	2014-01-14 23:00:07.887046648 -0600
+++ skia/skia_common.gypi	2014-01-14 23:00:22.624355238 -0600
@@ -61,7 +61,7 @@
     }],
 
     #Settings for text blitting, chosen to approximate the system browser.
-    [ 'OS == "linux"', {
+    [ 'OS == "linux" or os_bsd == 1', {
       'defines': [
         'SK_GAMMA_EXPONENT=1.2',
         'SK_GAMMA_CONTRAST=0.2',
