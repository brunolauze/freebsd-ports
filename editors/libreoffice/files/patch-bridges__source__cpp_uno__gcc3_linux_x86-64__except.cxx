--- bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx.orig	2014-01-21 11:44:03.567749396 -0600
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx	2014-01-22 11:50:16.914068537 -0600
@@ -45,10 +45,48 @@
 using namespace ::com::sun::star::uno;
 using namespace ::__cxxabiv1;
 
-
 namespace CPPU_CURRENT_NAMESPACE
 {
 
+
+namespace {
+
+struct Base {};
+struct Derived: Base {};
+
+struct Fake_type_info {
+    virtual ~Fake_type_info() {}
+    char const * name;
+};
+
+struct Fake_class_type_info: Fake_type_info {};
+
+struct Fake_si_class_type_info: Fake_class_type_info {
+    void const * base;
+};
+
+std::type_info * create_FAKE_class_type_info(char const * name) {
+    std::type_info * p = new FAKE_type_info(name);
+        // cxxabiv1::__class_type_info has no data members in addition to
+        // std::type_info
+    *reinterpret_cast< void ** >(p) = *reinterpret_cast< void * const * >(
+        &typeid(Base));
+        // copy correct __cxxabiv1::__class_type_info vtable into place
+    return p;
+}
+
+std::type_info * create_FAKE_si_class_type_info(
+    char const * name, std::type_info const * base)
+{
+    std::type_info * p = new FAKE_si_class_type_info(name, base);
+    *reinterpret_cast< void ** >(p) = *reinterpret_cast< void * const * >(
+        &typeid(Derived));
+        // copy correct __cxxabiv1::__si_class_type_info vtable into place
+    return p;
+}
+
+}
+
 //==================================================================================================
 static OUString toUNOname( char const * p ) SAL_THROW(())
 {
@@ -106,11 +144,7 @@
 };
 //__________________________________________________________________________________________________
 RTTI::RTTI() SAL_THROW(())
-#if defined(FREEBSD) && __FreeBSD_version < 702104
-    : m_hApp( dlopen( 0, RTLD_NOW | RTLD_GLOBAL ) )
-#else
     : m_hApp( dlopen( 0, RTLD_LAZY ) )
-#endif
 {
 }
 //__________________________________________________________________________________________________
@@ -145,11 +179,7 @@
         buf.append( 'E' );
 
         OString symName( buf.makeStringAndClear() );
-#if defined(FREEBSD) && __FreeBSD_version < 702104 /* #i22253# */
-        rtti = (type_info *)dlsym( RTLD_DEFAULT, symName.getStr() );
-#else
         rtti = (type_info *)dlsym( m_hApp, symName.getStr() );
-#endif
 
         if (rtti)
         {
@@ -175,13 +205,13 @@
                     // ensure availability of base
                     type_info * base_rtti = getRTTI(
                         (typelib_CompoundTypeDescription *)pTypeDescr->pBaseTypeDescription );
-                    rtti = new __si_class_type_info(
-                        strdup( rttiName ), (__class_type_info *)base_rtti );
+                    rtti = create_FAKE_si_class_type_info(
+                        strdup( rttiName ), base_rtti );
                 }
                 else
                 {
                     // this class has no base class
-                    rtti = new __class_type_info( strdup( rttiName ) );
+                    rtti = create_FAKE_class_type_info( strdup( rttiName ) );
                 }
 
                 pair< t_rtti_map::iterator, bool > insertion (
@@ -272,6 +302,7 @@
     __cxxabiv1::__cxa_throw( pCppExc, rtti, deleteException );
 }
 
+
 //==================================================================================================
 void fillUnoException( __cxa_exception * header, uno_Any * pUnoExc, uno_Mapping * pCpp2Uno )
 {
