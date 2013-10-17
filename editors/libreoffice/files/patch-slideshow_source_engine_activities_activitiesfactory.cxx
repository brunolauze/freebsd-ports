--- slideshow/source/engine/activities/activitiesfactory.cxx.orig	2013-10-14 18:03:58.383361385 -0500
+++ slideshow/source/engine/activities/activitiesfactory.cxx	2013-10-14 18:06:42.096351667 -0500
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
@@ -557,7 +557,7 @@
         // interpolate between nIndex and nIndex+1 values
         (*mpAnim)(
             getPresentationValue(
-                accumulate( maValues.back(),
+                accumulate<ValueType>( maValues.back(),
                             mbCumulative ? nRepeatCount : 0,
                             maInterpolator( maValues[ nIndex ],
                                             maValues[ nIndex+1 ],
@@ -577,7 +577,7 @@
         // this is discrete, thus no lerp here.
         (*mpAnim)(
             getPresentationValue(
-                accumulate( maValues.back(),
+                accumulate<ValueType>( maValues.back(),
                             mbCumulative ? nRepeatCount : 0,
                             maValues[ nFrame ] ) ) );
     }
