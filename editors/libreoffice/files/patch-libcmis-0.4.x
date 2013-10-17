--- ucb/source/ucp/cmis/auth_provider.hxx.orig	2013-10-11 13:31:31.365091955 -0500
+++ ucb/source/ucp/cmis/auth_provider.hxx	2013-10-11 13:32:01.006091029 -0500
@@ -9,7 +9,7 @@
 #ifndef AUTH_PROVIDER_HXX
 #define AUTH_PROVIDER_HXX
 
-#include <libcmis/session.hxx>
+#include <libcmis/libcmis.hxx>
 
 #include <com/sun/star/ucb/XCommandEnvironment.hpp>
 
--- ucb/source/ucp/cmis/cmis_content.cxx.orig	2013-10-11 13:35:24.356075686 -0500
+++ ucb/source/ucp/cmis/cmis_content.cxx	2013-10-11 13:36:10.348075724 -0500
@@ -32,7 +32,7 @@
 #include <com/sun/star/ucb/XCommandInfo.hpp>
 #include <com/sun/star/ucb/XDynamicResultSet.hpp>
 
-#include <libcmis/document.hxx>
+#include <libcmis/libcmis.hxx>
 
 #include <comphelper/processfactory.hxx>
 #include <ucbhelper/cancelcommandexecution.hxx>
--- ucb/source/ucp/cmis/cmis_content.hxx.orig	2013-10-11 13:38:14.249063945 -0500
+++ ucb/source/ucp/cmis/cmis_content.hxx	2013-10-11 13:38:26.878766204 -0500
@@ -21,7 +21,7 @@
 #include <com/sun/star/ucb/TransferInfo.hpp>
 #include <com/sun/star/ucb/XContentCreator.hpp>
 #include <ucbhelper/contenthelper.hxx>
-#include <libcmis/session-factory.hxx>
+#include <libcmis/libcmis.hxx>
 
 #include <list>
 
--- ucb/source/ucp/cmis/cmis_repo_content.cxx.orig	2013-10-11 13:40:59.593052402 -0500
+++ ucb/source/ucp/cmis/cmis_repo_content.cxx	2013-10-11 13:44:40.513045112 -0500
@@ -40,7 +40,7 @@
 {
     RepoContent::RepoContent( const uno::Reference< uno::XComponentContext >& rxContext,
         ContentProvider *pProvider, const uno::Reference< ucb::XContentIdentifier >& Identifier,
-        list< libcmis::RepositoryPtr > aRepos )
+        vector< libcmis::RepositoryPtr > aRepos )
             throw ( ucb::ContentCreationException )
         : ContentImplHelper( rxContext, pProvider, Identifier ),
         m_pProvider( pProvider ),
@@ -169,7 +169,7 @@
 
         if ( !m_sRepositoryId.isEmpty() )
         {
-            for ( list< libcmis::RepositoryPtr >::iterator it = m_aRepositories.begin( );
+            for ( vector< libcmis::RepositoryPtr >::iterator it = m_aRepositories.begin( );
                     it != m_aRepositories.end( ) && NULL == repo.get( ); ++it )
             {
                 if ( STD_TO_OUSTR( ( *it )->getId( ) ) == m_sRepositoryId )
@@ -349,7 +349,7 @@
 
         if ( m_sRepositoryId.isEmpty( ) )
         {
-            for ( list< libcmis::RepositoryPtr >::iterator it = m_aRepositories.begin( );
+            for ( vector< libcmis::RepositoryPtr >::iterator it = m_aRepositories.begin( );
                     it != m_aRepositories.end(); ++it )
             {
                 URL aUrl( m_aURL );
--- ucb/source/ucp/cmis/cmis_repo_content.hxx.orig	2013-10-11 13:48:03.950023622 -0500
+++ ucb/source/ucp/cmis/cmis_repo_content.hxx	2013-10-11 13:48:52.518714505 -0500
@@ -20,8 +20,9 @@
 #include <com/sun/star/ucb/TransferInfo.hpp>
 #include <com/sun/star/ucb/XContentCreator.hpp>
 #include <ucbhelper/contenthelper.hxx>
-#include <libcmis/repository.hxx>
+#include <libcmis/libcmis.hxx>
 
+#include <vector>
 #include <list>
 
 namespace com { namespace sun { namespace star {
@@ -52,7 +53,7 @@
     URL                    m_aURL;
     OUString          m_sRepositoryId;
 
-    std::list< libcmis::RepositoryPtr > m_aRepositories;
+    std::vector< libcmis::RepositoryPtr > m_aRepositories;
 
 private:
 
@@ -76,7 +77,7 @@
     RepoContent( const com::sun::star::uno::Reference<
         com::sun::star::uno::XComponentContext >& rxContext, ContentProvider *pProvider,
         const com::sun::star::uno::Reference< com::sun::star::ucb::XContentIdentifier >& Identifier,
-        std::list< libcmis::RepositoryPtr > aRepos = std::list< libcmis::RepositoryPtr > ( ) )
+        std::vector< libcmis::RepositoryPtr > aRepos = std::vector< libcmis::RepositoryPtr > ( ) )
             throw ( com::sun::star::ucb::ContentCreationException );
 
     virtual ~RepoContent();
--- ucb/source/ucp/cmis/cmis_url.cxx.orig	2013-10-11 13:49:40.257057616 -0500
+++ ucb/source/ucp/cmis/cmis_url.cxx	2013-10-11 13:49:54.047425498 -0500
@@ -7,7 +7,7 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/.
  */
 
-#include <libcmis/session-factory.hxx>
+#include <libcmis/libcmis.hxx>
 
 #include <rtl/uri.hxx>
 
