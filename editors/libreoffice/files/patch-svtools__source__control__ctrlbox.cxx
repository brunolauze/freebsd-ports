--- svtools/source/control/ctrlbox.cxx.orig	2013-10-11 14:20:18.687890740 -0500
+++ svtools/source/control/ctrlbox.cxx	2013-10-11 14:20:35.969890256 -0500
@@ -868,7 +868,7 @@
         if ( nPos < pLineList->size() ) {
             ImpLineList::iterator it = pLineList->begin();
             ::std::advance( it, nPos );
-            pLineList->insert( it, reinterpret_cast<ImpLineListData *>(NULL) );
+            pLineList->insert( it, static_cast<ImpLineListData *>(NULL) );
         } else {
             pLineList->push_back( NULL );
         }
