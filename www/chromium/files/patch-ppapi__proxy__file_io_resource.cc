--- ppapi/proxy/file_io_resource.cc.orig	2014-01-19 22:48:01.894943358 -0600
+++ ppapi/proxy/file_io_resource.cc	2014-01-19 22:48:55.054662586 -0600
@@ -288,10 +288,10 @@
     int64_t actual_offset =
         (open_flags_ & PP_FILEOPENFLAG_APPEND) ? max_written_offset_ : offset;
 
-    uint64_t max_offset = actual_offset + bytes_to_write;
-    if (max_offset > static_cast<uint64_t>(std::numeric_limits<int64_t>::max()))
+    uint64_t max_offset_write = actual_offset + bytes_to_write;
+    if (max_offset_write > static_cast<uint64_t>(std::numeric_limits<int64_t>::max()))
       return PP_ERROR_FAILED;  // amount calculation would overflow.
-    int64_t increase = static_cast<int64_t>(max_offset) - max_written_offset_;
+    int64_t increase = static_cast<int64_t>(max_offset_write) - max_written_offset_;
     if (increase > 0) {
       int64_t result =
           file_system_resource_->AsPPB_FileSystem_API()->RequestQuota(
@@ -302,7 +302,7 @@
       if (result == PP_OK_COMPLETIONPENDING)
         return PP_OK_COMPLETIONPENDING;
       DCHECK(result == increase);
-      max_written_offset_ = max_offset;
+      max_written_offset_ = max_offset_write;
     }
   }
   return WriteValidated(offset, buffer, bytes_to_write, callback);
