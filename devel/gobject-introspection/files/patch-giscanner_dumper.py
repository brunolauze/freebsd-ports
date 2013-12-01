--- giscanner/dumper.py.orig	2013-11-23 15:54:14.028253196 -0600
+++ giscanner/dumper.py	2013-11-23 15:54:57.367870851 -0600
@@ -90,7 +90,7 @@
         # the Microsoft compiler is used
         # (This is the other way to check whether Visual C++ is used subsequently)
         args = self._compiler_cmd.split()
-        if 'cl.exe' in args or 'cl' in args:
+        if 'clang' in args or 'cl.exe' in args or 'cl' in args:
             self._pkgconfig_msvc_flags = '--msvc-syntax'
         self._uninst_srcdir = os.environ.get(
             'UNINSTALLED_INTROSPECTION_SRCDIR')
