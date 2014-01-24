--- build/common.gypi.orig	2014-01-13 09:00:14.000000000 -0600
+++ build/common.gypi	2014-01-23 10:19:55.063872174 -0600
@@ -9,6 +9,7 @@
   # Variables expected to be overriden on the GYP command line (-D) or by
   # ~/.gyp/include.gypi.
   'variables': {
+    'cef_directory': '',
     # Putting a variables dict inside another variables dict looks kind of
     # weird.  This is done so that 'host_arch', 'chromeos', etc are defined as
     # variables within the outer variables dict here.  This is necessary
@@ -565,7 +566,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or os_bsd==1) and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -582,7 +583,7 @@
         # on gnome-keyring. If that dependency is disabled, no gnome-keyring
         # support will be available. This option is useful
         # for Linux distributions and for Aura.
-        ['OS!="linux" or chromeos==1 or use_aura==1', {
+        ['(OS!="linux" and os_bsd!=1) or chromeos==1 or use_aura==1', {
           'use_gnome_keyring%': 0,
         }, {
           'use_gnome_keyring%': 1,
@@ -602,7 +603,7 @@
           'image_loader_extension%': 0,
         }],
 
-        ['OS=="win" or OS=="mac" or (OS=="linux" and chromeos==0)', {
+        ['OS=="win" or OS=="mac" or os_bsd==1 or (OS=="linux" and chromeos==0)', {
           'enable_one_click_signin%': 1,
         }],
 
@@ -795,7 +796,7 @@
         }, {
           'use_openmax_dl_fft%': 0,
         }],
-        ['OS=="win" or OS=="linux"', {
+        ['OS=="win" or OS=="linux" or os_bsd==1', {
             'enable_mdns%' : 1,
         }],
 
@@ -998,6 +999,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'prefix_dir%': '/usr',
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -1600,7 +1605,7 @@
         'use_cups%': 0,
       }],
 
-      ['enable_plugins==1 and (OS=="linux" or OS=="mac" or OS=="win" or google_tv==1)', {
+      ['enable_plugins==1 and (OS=="linux" or os_bsd==1 or OS=="mac" or OS=="win" or google_tv==1)', {
         'enable_pepper_cdms%': 1,
       }, {
         'enable_pepper_cdms%': 0,
@@ -3625,6 +3630,13 @@
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
