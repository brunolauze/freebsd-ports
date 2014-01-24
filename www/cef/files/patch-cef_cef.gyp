--- cef/cef.gyp.orig	2014-01-23 10:04:19.843670177 -0600
+++ cef/cef.gyp	2014-01-23 15:41:51.843200003 -0600
@@ -839,7 +839,6 @@
         '<(DEPTH)/base/base.gyp:base',
         '<(DEPTH)/base/base.gyp:base_prefs',
         '<(DEPTH)/base/third_party/dynamic_annotations/dynamic_annotations.gyp:dynamic_annotations',
-        '<(DEPTH)/components/components.gyp:breakpad_component',
         '<(DEPTH)/components/components.gyp:navigation_interception',
         '<(DEPTH)/content/content.gyp:content_app_both',
         '<(DEPTH)/content/content.gyp:content_browser',
@@ -983,8 +982,6 @@
         'libcef/browser/xml_reader_impl.h',
         'libcef/browser/zip_reader_impl.cc',
         'libcef/browser/zip_reader_impl.h',
-        'libcef/common/breakpad_client.cc',
-        'libcef/common/breakpad_client.h',
         'libcef/common/cef_message_generator.cc',
         'libcef/common/cef_message_generator.h',
         'libcef/common/cef_messages.cc',
@@ -1138,6 +1135,15 @@
             '<(DEPTH)/chrome/renderer/printing/print_web_view_helper_mac.mm',
           ],
         }],
+	[ 'OS=="linux"', {
+	  'depenencies':[
+	    '<(DEPTH)/components/components.gyp:breakpad_component',
+	  ],
+	  'sources': [
+	    'libcef/common/breakpad_client.cc'
+            'libcef/common/breakpad_client.h',
+	  ],
+	}],
         [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
           'dependencies':[
             '<(DEPTH)/build/linux/system.gyp:gtkprint',
@@ -1165,7 +1171,7 @@
             '<(DEPTH)/chrome/renderer/printing/print_web_view_helper_linux.cc',
           ],
         }],
-        ['os_posix == 1 and OS != "mac" and android_webview_build != 1', {
+        ['os_posix == 1 and OS != "freebsd" and OS != "mac" and android_webview_build != 1', {
           'dependencies': [
             '<(DEPTH)/components/components.gyp:breakpad_host',
           ],
@@ -1321,7 +1327,7 @@
               # but this seems like a really good place to store them.
               'postbuild_name': 'Tweak Info.plist',
               'action': ['../build/mac/tweak_info_plist.py',
-                         '--breakpad=1',
+                         '--breakpad=0',
                          '--keystone=0',
                          '--scm=1',
                          '--version=<(chrome_version)',
@@ -1648,9 +1654,13 @@
               },
             },
           }],
-          [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+	  [ 'OS=="linux"', {
             'dependencies':[
               '<(DEPTH)/base/allocator/allocator.gyp:allocator',
+	    ],
+	  }],
+          [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+            'dependencies':[
               '<(DEPTH)/build/linux/system.gyp:gtk',
               '<(DEPTH)/build/linux/system.gyp:gtkprint',
             ],
