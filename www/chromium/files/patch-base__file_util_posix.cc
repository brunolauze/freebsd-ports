--- base/file_util_posix.cc.orig	2014-01-14 20:57:07.506002890 -0600
+++ base/file_util_posix.cc	2014-01-14 20:58:02.296429052 -0600
@@ -673,7 +673,7 @@
 #endif  // defined(OS_ANDROID)
   results->is_directory = S_ISDIR(file_info.st_mode);
   results->size = file_info.st_size;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || (defined(OS_FREEBSD) && __FreeBSD_version < 900000)
   results->last_modified = Time::FromTimeSpec(file_info.st_mtimespec);
   results->last_accessed = Time::FromTimeSpec(file_info.st_atimespec);
   results->creation_time = Time::FromTimeSpec(file_info.st_ctimespec);
