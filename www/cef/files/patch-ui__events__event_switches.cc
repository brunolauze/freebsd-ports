--- ui/events/event_switches.cc.orig	2014-01-17 17:00:14.915540054 -0600
+++ ui/events/event_switches.cc	2014-01-17 17:00:41.186297023 -0600
@@ -20,7 +20,7 @@
 //   disabled: touch events are disabled.
 const char kTouchEventsDisabled[] = "disabled";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
