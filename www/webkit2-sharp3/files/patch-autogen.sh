--- autogen.sh.orig	2014-01-24 16:09:03.261944009 -0600
+++ autogen.sh	2014-01-24 16:09:16.771271598 -0600
@@ -2,4 +2,5 @@
 
 mkdir -p m4
 autoreconf  -i --force --warnings=none -I . -I m4
+automake --foreign
 ./configure --enable-maintainer-mode $*
