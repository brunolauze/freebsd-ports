--- binaryurp/source/lessoperators.cxx.orig	2013-10-14 17:52:23.141409156 -0500
+++ binaryurp/source/lessoperators.cxx	2013-10-14 17:54:57.824399092 -0500
@@ -38,8 +38,30 @@
     typelib_TypeClass tc2 = right.get()->eTypeClass;
     return tc1 < tc2 ||
         (tc1 == tc2 &&
-         (OUString(left.get()->pTypeName) <
-          OUString(right.get()->pTypeName)));
+         (OUString::unacquired(&left.get()->pTypeName) <
+          OUString::unacquired(&right.get()->pTypeName)));
+}
+
+bool TypeDescEqual::operator()( const TypeDescription& rLeft, const TypeDescription& rRight) const
+{
+	assert( rLeft.is() && rRight.is());
+	const typelib_TypeDescription& rA = *rLeft.get();
+	const typelib_TypeDescription& rB = *rRight.get();
+	if( rA.eTypeClass != rB.eTypeClass)
+		return false;
+	const sal_Int32 nCmp = rtl_ustr_compare_WithLength(
+			rA.pTypeName->buffer, rA.pTypeName->length,
+			rB.pTypeName->buffer, rB.pTypeName->length);
+	return (nCmp == 0);
+}
+
+sal_Int32 TypeDescHash::operator()( const TypeDescription& rTD) const
+{
+	assert( rTD.is());
+	const typelib_TypeDescription& rA = *rTD.get();
+	sal_Int32 h = rtl_ustr_hashCode_WithLength( rA.pTypeName->buffer, rA.pTypeName->length);
+	h ^= static_cast<sal_Int32>(rA.eTypeClass);
+	return h;
 }
 
 } } } }
@@ -47,8 +69,8 @@
 namespace rtl {
 
 bool operator <(ByteSequence const & left, ByteSequence const & right) {
-    for (sal_Int32 i = 0; i != std::min(left.getLength(), right.getLength());
-         ++i)
+    const sal_Int32 nLen = std::min( left.getLength(), right.getLength());
+    for( sal_Int32 i = 0; i < nLen; ++i )
     {
         if (left[i] < right[i]) {
             return true;
