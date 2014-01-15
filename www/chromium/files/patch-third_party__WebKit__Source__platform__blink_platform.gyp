--- third_party/WebKit/Source/platform/blink_platform.gyp.orig	2014-01-14 23:24:05.359246852 -0600
+++ third_party/WebKit/Source/platform/blink_platform.gyp	2014-01-14 23:26:22.066567883 -0600
@@ -193,7 +193,7 @@
     # compiler optimizations, see crbug.com/237063
     'msvs_disabled_warnings': [ 4267, 4334, 4724 ],
     'conditions': [
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or os_bsd == 1', {
         'sources/': [
           # Cherry-pick files excluded by the broader regular expressions above.
           ['include', 'fonts/harfbuzz/FontHarfBuzz\\.cpp$'],
@@ -208,7 +208,7 @@
         'dependencies': [
           '<(DEPTH)/third_party/harfbuzz-ng/harfbuzz.gyp:harfbuzz-ng',
         ],
-      }, { # OS!="linux" and OS!="android"
+      }, { # OS!="linux" and OS!="android and os_bsd != 1"
         'sources/': [
           ['exclude', 'Harfbuzz[^/]+\\.(cpp|h)$'],
         ],
@@ -303,7 +303,7 @@
           ['exclude', 'fonts/harfbuzz/HarfBuzzFaceCoreText\\.cpp$'],
         ],
       }],
-      ['OS != "linux" and OS != "mac" and (OS != "win" or (OS == "win" and "ENABLE_GDI_FONTS_ON_WINDOWS=1" in feature_defines))', {
+      ['OS != "linux" and OS != "mac" and os_bsd != 1 and (OS != "win" or (OS == "win" and "ENABLE_GDI_FONTS_ON_WINDOWS=1" in feature_defines))', {
         'sources/': [
           ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
         ],
@@ -390,7 +390,7 @@
           ['exclude', 'Android\\.cpp$'],
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or os_bsd == 1', {
         'dependencies': [
           '<(DEPTH)/build/linux/system.gyp:fontconfig',
         ],
