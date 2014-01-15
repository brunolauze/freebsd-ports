--- cogl/cogl-attribute-buffer.c.orig	2014-01-14 18:07:07.375375881 -0600
+++ cogl/cogl-attribute-buffer.c	2014-01-14 18:07:22.675303336 -0600
@@ -37,7 +37,6 @@
 static void _cogl_attribute_buffer_free (CoglAttributeBuffer *array);
 
 COGL_BUFFER_DEFINE (AttributeBuffer, attribute_buffer);
-COGL_GTYPE_DEFINE_CLASS (AttributeBuffer, attribute_buffer);
 
 CoglAttributeBuffer *
 cogl_attribute_buffer_new_with_size (CoglContext *context,
