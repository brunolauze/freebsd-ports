--- vcl/unx/gtk/gdi/salnativewidgets-gtk.cxx.orig	2013-10-11 14:12:26.237923076 -0500
+++ vcl/unx/gtk/gdi/salnativewidgets-gtk.cxx	2013-10-11 14:13:01.108922859 -0500
@@ -4083,7 +4083,7 @@
     aStyleSet.SetPreferredSymbolsStyleName( OUString::createFromAscii( pIconThemeName ) );
     g_free( pIconThemeName );
 
-    aStyleSet.SetToolbarIconSize( STYLE_TOOLBAR_ICONSIZE_LARGE );
+    aStyleSet.SetToolbarIconSize( nDispDPIY > 160 ? STYLE_TOOLBAR_ICONSIZE_LARGE : STYLE_TOOLBAR_ICONSIZE_SMALL );
 
 #if !GTK_CHECK_VERSION(2,9,0)
     static cairo_font_options_t* (*gdk_screen_get_font_options)(GdkScreen*) =
