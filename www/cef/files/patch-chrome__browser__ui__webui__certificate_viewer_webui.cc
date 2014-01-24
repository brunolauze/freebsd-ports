--- chrome/browser/ui/webui/certificate_viewer_webui.cc.orig	2014-01-19 23:09:35.159804904 -0600
+++ chrome/browser/ui/webui/certificate_viewer_webui.cc	2014-01-19 23:14:03.198066830 -0600
@@ -229,7 +229,8 @@
   if (cert_index < 0)
     return;
 
-  NativeWebContentsModalDialog window =
+  /* NativeWebContentsModalDialog window = */
+  gfx::NativeWindow window =
       platform_util::GetTopLevel(dialog_->dialog()->GetNativeDialog());
   ShowCertExportDialog(web_ui()->GetWebContents(),
                        window,
