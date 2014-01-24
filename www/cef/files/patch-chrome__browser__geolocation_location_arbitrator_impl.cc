--- content/browser/geolocation/location_arbitrator_impl.cc.orig	2014-01-19 23:56:20.390945109 -0600
+++ content/browser/geolocation/location_arbitrator_impl.cc	2014-01-20 00:01:38.829228779 -0600
@@ -107,7 +107,8 @@
   LocationProvider* provider =
       GetContentClient()->browser()->OverrideSystemLocationProvider();
   if (!provider)
-    provider = NewSystemLocationProvider();
+	return;
+    /*provider = NewSystemLocationProvider(); */
   RegisterProvider(provider);
   DoStartProviders();
 }
@@ -160,7 +161,7 @@
 }
 
 LocationProvider* LocationArbitratorImpl::NewSystemLocationProvider() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return NULL;
 #else
   return content::NewSystemLocationProvider();
