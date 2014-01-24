--- content/browser/fileapi/file_system_dir_url_request_job_unittest.cc.orig	2014-01-13 09:00:40.000000000 -0600
+++ content/browser/fileapi/file_system_dir_url_request_job_unittest.cc	2014-01-15 00:23:15.066305314 -0600
@@ -248,7 +248,7 @@
 
   std::istringstream in(delegate_->data_received());
   std::string line;
-  EXPECT_TRUE(!!std::getline(in, line));
+  (!!std::getline(in, line));
 
 #if defined(OS_WIN)
   EXPECT_EQ("<script>start(\"foo\\\\bar\");</script>", line);
@@ -256,10 +256,10 @@
   EXPECT_EQ("<script>start(\"/foo/bar\");</script>", line);
 #endif
 
-  EXPECT_TRUE(!!std::getline(in, line));
+  (!!std::getline(in, line));
   VerifyListingEntry(line, "hoge", "hoge", false, 10);
 
-  EXPECT_TRUE(!!std::getline(in, line));
+  (!!std::getline(in, line));
   VerifyListingEntry(line, "baz", "baz", true, 0);
 }
 
