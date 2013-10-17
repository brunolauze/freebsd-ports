#!/bin/sh

find . -name "libPlatform_la-*.o" -exec ar r WebCoreLayer.a {} +
find . -name "libPlatformGtk_la-*.o" -exec ar r WebCoreLayer.a {} +
find . -name "libWebCorePlatform_la-*.o" -exec ar r WebCoreLayer.a {} +
find . -name "libWebCoreGtk_la-*.o" -exec ar r WebCoreLayer.a {} +
find . -name "libWebCore_la-*" -exec ar r WebCoreLayer.a {} +
find . -name "libWebCoreModules_la-*.o" -exec ar r WebCoreLayer.a {} +
find . -name "libWebCoreSVG_la-*.o" -exec ar r WebCoreLayer.a {} +
find . -name "libANGLE_la-*.o" -exec ar r WebCoreLayer.a {} +

