--- /dev/null	2014-01-24 06:55:00.000000000 -0600
+++ create_webcorelayergtk2.sh	2014-01-24 06:56:26.525471780 -0600
@@ -0,0 +1,10 @@
+#!/bin/sh
+
+find . -name "libPlatform_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
+find . -name "libPlatformGtk2_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
+find . -name "libWebCorePlatform_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
+find . -name "libWebCoreGtk2_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
+find . -name "libWebCore_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
+find . -name "libWebCoreModules_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
+find . -name "libWebCoreSVG_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
+find . -name "libANGLE_la-*" -exec ar r WebCoreLayerGtk2.a {} +
