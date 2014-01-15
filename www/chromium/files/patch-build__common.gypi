--- build/common.gypi.orig	2014-01-13 09:00:14.000000000 -0600
+++ build/common.gypi	2014-01-14 21:19:15.205843090 -0600
@@ -998,6 +998,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'prefix_dir%': '/usr',
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -3625,6 +3629,13 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+          '-pie',
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
       },
     }],
     # Android-specific options; note that most are set above with Linux.
