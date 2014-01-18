--- third_party/WebKit/Source/build/scripts/preprocessor.pm.orig	2014-01-16 21:22:50.726228528 -0600
+++ third_party/WebKit/Source/build/scripts/preprocessor.pm	2014-01-16 21:23:09.067061389 -0600
@@ -50,7 +50,7 @@
         } elsif (($Config::Config{'osname'}) =~ /solaris/i) {
             $preprocessor = "/usr/sfw/bin/gcc";
         } else {
-            $preprocessor = "/usr/bin/gcc";
+            $preprocessor = "/usr/bin/cc";
         }
         push(@args, qw(-E -P -x c++));
     }
