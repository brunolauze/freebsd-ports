--- cef/libcef/browser/url_request_context_getter.cc.orig	2014-01-23 14:35:42.073356921 -0600
+++ cef/libcef/browser/url_request_context_getter.cc	2014-01-23 16:03:17.763177628 -0600
@@ -28,6 +28,7 @@
 #include "base/threading/worker_pool.h"
 #include "chrome/browser/net/proxy_service_factory.h"
 #include "content/browser/net/sqlite_persistent_cookie_store.h"
+#include "chrome/browser/net/cookie_store_util.h"
 #include "content/public/browser/browser_thread.h"
 #include "content/public/browser/cookie_crypto_delegate.h"
 #include "content/public/common/content_client.h"
@@ -274,7 +275,7 @@
               BrowserThread::GetMessageLoopProxyForThread(BrowserThread::DB),
               persist_session_cookies,
               NULL,
-              scoped_ptr<content::CookieCryptoDelegate>());
+              NULL);
     } else {
       NOTREACHED() << "The cookie storage directory could not be created";
     }
