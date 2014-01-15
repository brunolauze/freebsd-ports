--- content/browser/browser_main_loop.cc.orig	2014-01-13 09:00:40.000000000 -0600
+++ content/browser/browser_main_loop.cc	2014-01-14 22:21:13.285970453 -0600
@@ -102,7 +102,7 @@
 #include "ui/gfx/gtk_util.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include <sys/stat.h>
 
 #include "content/browser/renderer_host/render_sandbox_host_linux.h"
@@ -125,7 +125,7 @@
 namespace content {
 namespace {
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SetupSandbox(const CommandLine& parsed_command_line) {
   TRACE_EVENT0("startup", "SetupSandbox");
   // TODO(evanm): move this into SandboxWrapper; I'm just trying to move this
@@ -348,7 +348,7 @@
 void BrowserMainLoop::EarlyInitialization() {
   TRACE_EVENT0("startup", "BrowserMainLoop::EarlyInitialization");
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // No thread should be created before this call, as SetupSandbox()
   // will end-up using fork().
   SetupSandbox(parsed_command_line_);
