--- modules/demux/mkv/mkv.hpp.orig	2013-10-15 13:21:19.736589438 -0500
+++ modules/demux/mkv/mkv.hpp	2013-10-15 13:22:04.824574202 -0500
@@ -120,8 +120,7 @@
 
 #define MKVD_TIMECODESCALE 1000000
 
-#define MKV_IS_ID( el, C ) ( el != NULL && typeid( *el ) == typeid( C ) )
-
+#define MKV_IS_ID( el, C ) ( EbmlId( (*el) ) == C::ClassInfos.GlobalId )
 
 using namespace LIBMATROSKA_NAMESPACE;
 using namespace std;
