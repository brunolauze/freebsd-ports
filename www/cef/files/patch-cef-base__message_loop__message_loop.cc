--- base/message_loop/message_loop.cc.orig	2014-01-23 10:24:32.533646468 -0600
+++ base/message_loop/message_loop.cc	2014-01-23 10:24:57.144107402 -0600
@@ -142,7 +142,7 @@
 MessageLoop::~MessageLoop() {
   DCHECK_EQ(this, current());
 
-  DCHECK(!run_loop_);
+  //DCHECK(!run_loop_);
 
   // Clean up any unprocessed tasks, but take care: deleting a task could
   // result in the addition of more tasks (e.g., via DeleteSoon).  We set a
