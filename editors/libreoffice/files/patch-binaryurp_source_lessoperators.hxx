--- binaryurp/source/lessoperators.hxx.orig	2013-10-14 17:55:22.145397286 -0500
+++ binaryurp/source/lessoperators.hxx	2013-10-14 17:56:33.337392245 -0500
@@ -31,6 +31,10 @@
 
 bool operator <(TypeDescription const & left, TypeDescription const & right);
 
+struct TypeDescHash { sal_Int32 operator()( const TypeDescription&) const; };
+
+struct TypeDescEqual { bool operator()( const TypeDescription&, const TypeDescription&) const; };
+
 } } } }
 
 namespace rtl {
