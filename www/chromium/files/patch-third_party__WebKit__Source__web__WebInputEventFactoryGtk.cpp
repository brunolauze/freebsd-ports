--- third_party/WebKit/Source/web/WebInputEventFactoryGtk.cpp.orig	2014-01-18 18:16:51.392917561 -0600
+++ third_party/WebKit/Source/web/WebInputEventFactoryGtk.cpp	2014-01-18 18:17:51.671261468 -0600
@@ -66,8 +66,8 @@
                  "gtk-double-click-time", &doubleClickTime,
                  "gtk-double-click-distance", &doubleClickDistance, NULL);
     return (time - gLastClickTime) > doubleClickTime
-           || abs(x - gLastClickX) > doubleClickDistance
-           || abs(y - gLastClickY) > doubleClickDistance;
+           || std::abs((double)(x - gLastClickX)) > doubleClickDistance
+           || std::abs((dobule)(y - gLastClickY)) > doubleClickDistance;
 }
 
 void resetClickCountState()
