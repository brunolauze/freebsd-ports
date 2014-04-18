--- ext/opencv/gsttemplatematch.c.orig	2014-01-14 08:25:52.438192534 -0600
+++ ext/opencv/gsttemplatematch.c	2014-01-14 08:26:18.821714712 -0600
@@ -407,7 +407,7 @@
 {
   if (filter->template) {
     filter->cvTemplateImage =
-        cvLoadImage (filter->template, CV_LOAD_IMAGE_COLOR);
+        cvLoadImage (filter->template, 1);
 
     if (!filter->cvTemplateImage) {
       GST_WARNING ("Couldn't load template image: %s. error: %s",
