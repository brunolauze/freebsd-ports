--- slideshow/source/engine/activities/activitiesfactory.cxx.orig	2013-12-24 12:05:06.999305060 -0600
+++ slideshow/source/engine/activities/activitiesfactory.cxx	2013-12-24 12:06:18.750478679 -0600
@@ -298,7 +298,7 @@
         if( mbCumulative && !mbDynamicStartValue )
         {
             // aValue = this.aEndValue * nRepeatCount + aValue;
-            aValue = accumulate( maEndValue, nRepeatCount, aValue );
+            aValue = accumulate<ValueType>( maEndValue, nRepeatCount, aValue );
         }
 
         (*mpAnim)( getPresentationValue( aValue ) );
@@ -319,7 +319,7 @@
             return;
         (*mpAnim)(
             getPresentationValue(
-                accumulate( maEndValue, mbCumulative ? nRepeatCount : 0,
+                accumulate<ValueType>( maEndValue, mbCumulative ? nRepeatCount : 0,
                             lerp( maInterpolator,
                                   (mbDynamicStartValue
                                    ? mpAnim->getUnderlyingValue()
