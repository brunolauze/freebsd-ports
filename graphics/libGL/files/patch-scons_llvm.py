--- scons/llvm.py.orig	2013-11-14 10:20:03.582868593 -0600
+++ scons/llvm.py	2013-11-14 10:20:21.612859628 -0600
@@ -177,7 +177,7 @@
             print 'scons: llvm-config script not found'
             return
 
-        llvm_version = env.backtick('llvm-config --version').rstrip()
+        llvm_version = '3.4'
         llvm_version = distutils.version.LooseVersion(llvm_version)
 
         try:
