--- cef/tools/cef_api_hash.py.orig	2014-01-23 13:28:19.843547289 -0600
+++ cef/tools/cef_api_hash.py	2014-01-23 13:31:25.873414704 -0600
@@ -26,7 +26,7 @@
         self.__verbose = verbose;
         self.__debug_enabled = not (self.__debugdir is None) and len(self.__debugdir) > 0;
 
-        self.platforms = [ "windows", "macosx", "linux" ];
+        self.platforms = [ "windows", "macosx", "linux", "freebsd" ];
 
         self.platform_files = {
             "windows": [
@@ -37,7 +37,10 @@
                 ],
             "linux": [
                 "internal/cef_types_linux.h"
-                ]
+                ],
+	    "freebsd": [
+		"internal/cef_types_linux.h"
+	        ]
             };
 
         self.included_files = [
