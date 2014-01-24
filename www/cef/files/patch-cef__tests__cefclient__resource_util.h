--- cef/tests/cefclient/resource_util.h.orig	2014-01-23 15:55:41.823702406 -0600
+++ cef/tests/cefclient/resource_util.h	2014-01-23 15:56:06.273177571 -0600
@@ -9,10 +9,8 @@
 #include <string>
 #include "include/cef_stream.h"
 
-#if defined(OS_POSIX)
 // Returns the directory containing resource files.
 bool GetResourceDir(std::string& dir);
-#endif
 
 // Retrieve a resource as a string.
 bool LoadBinaryResource(const char* resource_name, std::string& resource_data);
