--- third_party/WebKit/Source/build/scripts/scripts.gypi.orig	2014-01-16 21:24:14.656857202 -0600
+++ third_party/WebKit/Source/build/scripts/scripts.gypi	2014-01-16 21:24:34.486336831 -0600
@@ -55,9 +55,9 @@
                 'bison_exe': 'bison',
                 # We specify a preprocess so it happens locally and won't get
                 # distributed to goma.
-                # FIXME: /usr/bin/gcc won't exist on OSX forever. We want to
+                # FIXME: /usr/bin/cc won't exist on OSX forever. We want to
                 # use /usr/bin/clang once we require Xcode 4.x.
-                'preprocessor': '--preprocessor "/usr/bin/gcc -E -P -x c++"'
+                'preprocessor': '--preprocessor "/usr/bin/cc -E -P -x c++"'
               }],
          ],
     },
