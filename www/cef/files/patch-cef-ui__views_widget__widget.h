--- ui/views/widget/widget.h.orig	2014-01-23 10:30:37.033624563 -0600
+++ ui/views/widget/widget.h	2014-01-23 10:31:13.884042370 -0600
@@ -197,6 +197,7 @@
     // Should the widget be double buffered? Default is false.
     bool double_buffer;
     gfx::NativeView parent;
+    gfx::AcceleratedWidget parent_widget;
     // Specifies the initial bounds of the Widget. Default is empty, which means
     // the NativeWidget may specify a default size. If the parent is specified,
     // |bounds| is in the parent's coordinate system. If the parent is not
