--- Source/WebKit2/Platform/unix/SharedMemoryUnix.cpp.orig	2013-10-08 16:41:23.164161561 -0500
+++ Source/WebKit2/Platform/unix/SharedMemoryUnix.cpp	2013-10-08 16:42:19.709818957 -0500
@@ -107,7 +107,7 @@
         tempName = name.utf8();
 
         do {
-            fileDescriptor = shm_open(tempName.data(), O_CREAT | O_CLOEXEC | O_RDWR, S_IRUSR | S_IWUSR);
+            fileDescriptor = shm_open(tempName.data(), O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
         } while (fileDescriptor == -1 && errno == EINTR);
     }
     if (fileDescriptor == -1) {
