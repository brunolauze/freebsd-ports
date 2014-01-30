--- aclocal.m4.orig	2014-01-29 16:28:45.028402582 -0600
+++ aclocal.m4	2014-01-29 16:29:03.298472436 -0600
@@ -1,4 +1,4 @@
-# generated automatically by aclocal 1.14.1 -*- Autoconf -*-
+# generated automatically by aclocal 1.14 -*- Autoconf -*-
 
 # Copyright (C) 1996-2013 Free Software Foundation, Inc.
 
@@ -35,7 +35,7 @@
 [am__api_version='1.14'
 dnl Some users find AM_AUTOMAKE_VERSION and mistake it for a way to
 dnl require some minimum version.  Point them to the right macro.
-m4_if([$1], [1.14.1], [],
+m4_if([$1], [1.14], [],
       [AC_FATAL([Do not call $0, use AM_INIT_AUTOMAKE([$1]).])])dnl
 ])
 
@@ -51,7 +51,7 @@
 # Call AM_AUTOMAKE_VERSION and AM_AUTOMAKE_VERSION so they can be traced.
 # This function is AC_REQUIREd by AM_INIT_AUTOMAKE.
 AC_DEFUN([AM_SET_CURRENT_AUTOMAKE_VERSION],
-[AM_AUTOMAKE_VERSION([1.14.1])dnl
+[AM_AUTOMAKE_VERSION([1.14])dnl
 m4_ifndef([AC_AUTOCONF_VERSION],
   [m4_copy([m4_PACKAGE_VERSION], [AC_AUTOCONF_VERSION])])dnl
 _AM_AUTOCONF_VERSION(m4_defn([AC_AUTOCONF_VERSION]))])
