--- sandbox/sandbox.gyp.orig	2014-01-23 17:09:17.363093660 -0600
+++ sandbox/sandbox.gyp	2014-01-23 17:09:49.323093724 -0600
@@ -12,12 +12,12 @@
         'win/sandbox_win.gypi',
       ],
     }],
-    [ 'OS=="linux" or OS=="android"', {
+    [ 'OS=="linux" or os_bsd == 1 or OS=="android"', {
       'includes': [
         'linux/sandbox_linux.gypi',
       ],
     }],
-    [ 'OS!="win" and OS!="mac" and OS!="linux" and OS!="android"', {
+    [ 'OS!="win" and OS!="mac" and OS!="linux" and OS != "freebsd" and OS!="android"', {
       # A 'default' to accomodate the "sandbox" target.
       'targets': [
         {
