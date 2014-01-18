--- ui/events/event_switches.h.orig	2014-01-17 17:00:21.944683440 -0600
+++ ui/events/event_switches.h	2014-01-17 17:00:51.764669420 -0600
@@ -16,7 +16,7 @@
 EVENTS_BASE_EXPORT extern const char kTouchEventsEnabled[];
 EVENTS_BASE_EXPORT extern const char kTouchEventsDisabled[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
