--- sandbox/linux/services/broker_process.cc.orig	2014-01-23 17:25:29.773175105 -0600
+++ sandbox/linux/services/broker_process.cc	2014-01-23 17:26:08.673081129 -0600
@@ -102,7 +102,7 @@
 
   const int known_flags =
     O_APPEND | O_ASYNC | O_CLOEXEC | O_CREAT | O_DIRECT |
-    O_DIRECTORY | O_EXCL | O_LARGEFILE | O_NOATIME | O_NOCTTY |
+    O_DIRECTORY | O_EXCL | O_NOCTTY |
     O_NOFOLLOW | O_NONBLOCK | O_NDELAY | O_SYNC | O_TRUNC;
 
   const int unknown_flags = ~known_flags;
@@ -147,7 +147,7 @@
     return false;
   }
 
-  DCHECK_EQ(1, base::GetNumberOfThreads(base::GetCurrentProcessHandle()));
+  //DCHECK_EQ(1, base::GetNumberOfThreads(base::GetCurrentProcessHandle()));
   int child_pid = fork();
   if (child_pid == -1) {
     close(socket_pair[0]);
