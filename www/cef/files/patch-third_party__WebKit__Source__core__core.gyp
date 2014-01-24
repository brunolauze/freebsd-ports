--- third_party/WebKit/Source/core/core.gyp.orig	2014-01-20 00:36:32.229228823 -0600
+++ third_party/WebKit/Source/core/core.gyp	2014-01-20 00:46:51.289876943 -0600
@@ -336,7 +336,7 @@
           # Disable c4267 warnings until we fix size_t to int truncations.
           'msvs_disabled_warnings': [ 4065, 4267 ],
         }],
-        ['OS in ("linux", "android") and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
+        ['OS in ("linux", "freebsd", "freebsd10", "freebsd11", "android") and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
           'cflags': [
             '<!@(pkg-config --cflags-only-I ipp)',
           ],
@@ -450,7 +450,7 @@
             ['exclude', 'accessibility/'],
           ],
         }],
-        ['OS in ("linux", "android") and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
+        ['OS in ("linux", "freebsd", "freebsd10", "freebsd11", "android") and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
           'direct_dependent_settings': {
             'cflags': [
               '<!@(pkg-config --cflags-only-I ipp)',
@@ -592,7 +592,7 @@
         ['exclude', 'platform/Theme\\.cpp$'],
       ],
       'conditions': [
-        ['OS!="linux"', {
+        ['OS!="linux" and os_bsd!=1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
@@ -729,7 +729,7 @@
           # Due to a bug in gcc 4.6 in android NDK, we get warnings about uninitialized variable.
           'cflags': ['-Wno-uninitialized'],
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd!=1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
@@ -773,7 +773,7 @@
         ['OS=="win" and buildtype=="Official"', {
           'msvs_shard': 19,
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd!=1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
@@ -838,7 +838,7 @@
         ],
       },
       'conditions': [
-        ['OS=="linux" and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
+        ['(OS=="linux" or os_bsd==1) and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
           'link_settings': {
             'ldflags': [
               '<!@(pkg-config --libs-only-L ipp)',
