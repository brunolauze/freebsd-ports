--- third_party/WebKit/Source/web/WebInputEventFactoryGtk.cpp.orig	2013-11-08 07:50:07.000000000 +0100
+++ third_party/WebKit/Source/web/WebInputEventFactoryGtk.cpp	2013-11-15 19:38:46.000000000 +0100
@@ -65,8 +67,8 @@
                  "gtk-double-click-time", &doubleClickTime,
                  "gtk-double-click-distance", &doubleClickDistance, NULL);
     return (time - gLastClickTime) > doubleClickTime
-           || abs(x - gLastClickX) > doubleClickDistance
-           || abs(y - gLastClickY) > doubleClickDistance;
+           || std::abs(x - gLastClickX) > doubleClickDistance
+           || std::abs(y - gLastClickY) > doubleClickDistance;
 }
 
 void resetClickCountState()
