--- buildtools/wafsamba/samba_install.py.orig	2013-12-27 10:45:14.417609255 -0600
+++ buildtools/wafsamba/samba_install.py	2013-12-27 10:45:28.650031102 -0600
@@ -111,7 +111,7 @@
             inst_name    = bld.make_libname(t.target)
     elif self.vnum:
         vnum_base    = self.vnum.split('.')[0]
-        install_name = bld.make_libname(target_name, version=self.vnum)
+        install_name = bld.make_libname(target_name, version=vnum_base)
         install_link = bld.make_libname(target_name, version=vnum_base)
         inst_name    = bld.make_libname(t.target)
         if not self.private_library:
