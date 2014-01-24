--- third_party/libjingle/source/talk/base/cpumonitor.cc.orig	2014-01-13 09:02:12.000000000 -0600
+++ third_party/libjingle/source/talk/base/cpumonitor.cc	2014-01-15 00:00:17.300548420 -0600
@@ -52,13 +52,13 @@
 #include <mach/task.h>
 #endif  // defined(IOS) || defined(OSX)
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include <sys/resource.h>
 #include <errno.h>
 #include <stdio.h>
 #include "talk/base/fileutils.h"
 #include "talk/base/pathutils.h"
-#endif // defined(LINUX) || defined(ANDROID)
+#endif // defined(LINUX) || defined(ANDROID) || defined(BSD)
 
 #if defined(IOS) || defined(OSX)
 static uint64 TimeValueTToInt64(const time_value_t &time_value) {
@@ -287,13 +287,16 @@
   const uint64 cpu_times = 0;
   const uint64 total_times = 0;
 #endif  // defined(__native_client__)
-
+#if defined(OS_BSD)
+  return 0.f;
+#else
   system_.prev_load_time_ = timenow;
   system_.prev_load_ = UpdateCpuLoad(total_times,
                                      cpu_times * cpus_,
                                      &system_.prev_total_times_,
                                      &system_.prev_cpu_times_);
   return system_.prev_load_;
+#endif
 }
 
 float CpuSampler::GetProcessLoad() {
@@ -355,7 +358,7 @@
       TimeValueTToInt64(task_term_info.system_time));
 #endif  // defined(IOS) || defined(OSX)
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
   rusage usage;
   if (getrusage(RUSAGE_SELF, &usage) < 0) {
     LOG_ERR(LS_ERROR) << "getrusage failed";
