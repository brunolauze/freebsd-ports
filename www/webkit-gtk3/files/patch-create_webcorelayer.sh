--- /dev/null	2014-01-24 06:55:00.000000000 -0600
+++ create_webcorelayer.sh	2014-01-24 06:56:26.525471780 -0600
@@ -0,0 +1,11 @@
+#!/bin/sh
+
+find . -name "libPlatform_la-*.o" -exec ar r WebCoreLayer.a {} +
+find . -name "libPlatformGtk_la-*.o" -exec ar r WebCoreLayer.a {} +
+find . -name "libWebCorePlatform_la-*.o" -exec ar r WebCoreLayer.a {} +
+find . -name "libWebCoreGtk_la-*.o" -exec ar r WebCoreLayer.a {} +
+find . -name "libWebCore_la-*" -exec ar r WebCoreLayer.a {} +
+find . -name "libWebCoreModules_la-*.o" -exec ar r WebCoreLayer.a {} +
+find . -name "libWebCoreSVG_la-*.o" -exec ar r WebCoreLayer.a {} +
+find . -name "libANGLE_la-*.o" -exec ar r WebCoreLayer.a {} +
+
