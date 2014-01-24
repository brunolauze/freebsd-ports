--- cef/libcef/browser/cookie_manager_impl.cc.orig	2014-01-23 14:25:20.694195345 -0600
+++ cef/libcef/browser/cookie_manager_impl.cc	2014-01-23 16:01:51.733240962 -0600
@@ -40,6 +40,7 @@
       visitor_(visitor) {
   }
 
+
   void Run(const net::CookieList& list) {
     CEF_REQUIRE_IOT();
 
@@ -300,7 +301,7 @@
                 BrowserThread::GetMessageLoopProxyForThread(BrowserThread::DB),
                 persist_session_cookies,
                 NULL,
-                scoped_ptr<content::CookieCryptoDelegate>());
+                NULL);
       } else {
         NOTREACHED() << "The cookie storage directory could not be created";
         storage_path_.clear();
