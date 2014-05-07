--- src/Pegasus/IndicationService/IndicationService.cpp.orig	2014-02-28 21:09:50.920639497 -0600
+++ src/Pegasus/IndicationService/IndicationService.cpp	2014-02-28 21:10:42.100112969 -0600
@@ -128,9 +128,9 @@
 static const char _MSG_NO_PROVIDER[] =
     "Subscription ($0) in namespace $1 has no provider";
 
-static const char _MSG_STATE_CHANGE_FAILED_KEY[] =
+static const char __unused _MSG_STATE_CHANGE_FAILED_KEY[] =
     "IndicationService.IndicationService.STATE_CHANGE_FAILED";
-static const char _MSG_STATE_CHANGE_FAILED[] =
+static const char __unused _MSG_STATE_CHANGE_FAILED[] =
     "The requested state change failed : $0. Current IndicationService"
         " EnabledState : $1, HealthState : $2.";
 
