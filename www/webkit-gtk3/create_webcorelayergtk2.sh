#!/bin/sh

find . -name "libPlatform_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
find . -name "libPlatformGtk2_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
find . -name "libWebCorePlatform_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
find . -name "libWebCoreGtk2_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
find . -name "libWebCore_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
find . -name "libWebCoreModules_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
find . -name "libWebCoreSVG_la-*.o" -exec ar r WebCoreLayerGtk2.a {} +
find . -name "libANGLE_la-*" -exec ar r WebCoreLayerGtk2.a {} +
