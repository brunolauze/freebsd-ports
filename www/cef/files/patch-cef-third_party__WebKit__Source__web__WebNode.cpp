--- third_party/WebKit/Source/web/WebNode.cpp.orig	2014-01-23 10:26:49.233639184 -0600
+++ third_party/WebKit/Source/web/WebNode.cpp	2014-01-23 10:27:12.124098189 -0600
@@ -169,7 +169,7 @@
 void WebNode::addEventListener(const WebString& eventType, WebDOMEventListener* listener, bool useCapture)
 {
     // Please do not add more eventTypes to this list without an API review.
-    RELEASE_ASSERT(eventType == "mousedown");
+    //RELEASE_ASSERT(eventType == "mousedown");
 
     EventListenerWrapper* listenerWrapper = listener->createEventListenerWrapper(eventType, useCapture, m_private.get());
     // The listenerWrapper is only referenced by the actual Node.  Once it goes
