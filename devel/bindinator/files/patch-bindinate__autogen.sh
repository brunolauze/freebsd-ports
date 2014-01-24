--- bindinate/autogen.sh.orig	2014-01-24 17:01:02.869579915 -0600
+++ bindinate/autogen.sh	2014-01-24 17:01:12.389055924 -0600
@@ -2,4 +2,5 @@
 
 mkdir -p m4
 autoreconf  -i --force --warnings=none -I . -I m4
+automake --foreign
 ./configure --enable-maintainer-mode $*
