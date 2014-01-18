--- tools/gyp/pylib/gyp/common_test.py.orig	2014-01-16 19:35:22.960916640 -0600
+++ tools/gyp/pylib/gyp/common_test.py	2014-01-16 19:35:57.421504060 -0600
@@ -58,6 +58,7 @@
   def test_platform_default(self):
     self.assertFlavor('freebsd', 'freebsd9' , {})
     self.assertFlavor('freebsd', 'freebsd10', {})
+    self.assertFlavor('freebsd', 'freebsd11', {})
     self.assertFlavor('openbsd', 'openbsd5' , {})
     self.assertFlavor('solaris', 'sunos5'   , {});
     self.assertFlavor('solaris', 'sunos'    , {});
