--- utils/llvm-build/llvmbuild/main.py.orig	2014-01-14 08:12:12.456807590 -0600
+++ utils/llvm-build/llvmbuild/main.py	2014-01-14 08:12:57.506029478 -0600
@@ -660,9 +660,12 @@
 
     # We handle a few special cases of target names here for historical
     # reasons, as these are the names configure currently comes up with.
-    native_target_name = { 'x86' : 'X86',
-                           'x86_64' : 'X86',
-                           'Unknown' : None }.get(opts.native_target,
+    native_target_name = { 'amd64' : 'X86',
+                          'arm' : 'ARM',
+                          'i386' : 'X86',
+                          'x86' : 'X86',
+                          'x86_64' : 'X86',
+                          'Unknown' : None }.get(opts.native_target,
                                                   opts.native_target)
     if native_target_name is None:
         native_target = None
