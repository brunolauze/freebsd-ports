--- sysui/desktop/share/create_tree.sh.orig	2013-10-11 14:15:23.024911365 -0500
+++ sysui/desktop/share/create_tree.sh	2013-10-11 14:17:31.487903732 -0500
@@ -57,32 +57,32 @@
   chmod 0644 "${DESTDIR}/${GNOMEDIR}/share/application-registry/${PREFIX}".*
 fi
 
-mkdir -p "${DESTDIR}/usr/bin"
+mkdir -p "${DESTDIR}/${PREFIXSDIR}/bin"
 
 test -n "${OFFICE_PREFIX}" && office_prefix="${OFFICE_PREFIX}" || office_prefix=/opt
 office_root=${office_prefix}/${PREFIX}
 
 #this symlink is needed to have the API boostrap functions running right
-ln -sf "${office_root}/program/soffice" "${DESTDIR}/usr/bin/${PREFIX}"
+ln -sf "${office_root}/program/soffice" "${DESTDIR}/${PREFIXSDIR}/bin/${PREFIX}"
 
-cp printeradmin.sh "${DESTDIR}/usr/bin/${PREFIX}-printeradmin"
-chmod 0755 "${DESTDIR}/usr/bin/${PREFIX}-printeradmin"
+cp printeradmin.sh "${DESTDIR}/${PREFIXSDIR}/bin/${PREFIX}-printeradmin"
+chmod 0755 "${DESTDIR}/${PREFIXSDIR}/bin/${PREFIX}-printeradmin"
 
 if test "${PREFIX}" != libreoffice${PRODUCTVERSION} -a "${PREFIX}" != libreofficedev${PRODUCTVERSION}  ; then
     # compat symlinks
     mkdir -p "${DESTDIR}${office_prefix}"
     ln -sf libreoffice${PRODUCTVERSION} "${DESTDIR}${office_root}"
-    ln -sf /usr/bin/${PREFIX} "${DESTDIR}/usr/bin/libreoffice${PRODUCTVERSION}"
-    ln -sf /usr/bin/${PREFIX}-printeradmin "${DESTDIR}/usr/bin/libreoffice${PRODUCTVERSION}-printeradmin"
+    ln -sf /${PREFIXSDIR}/bin/${PREFIX} "${DESTDIR}/${PREFIXSDIR}/bin/libreoffice${PRODUCTVERSION}"
+    ln -sf /${PREFIXSDIR}/bin/${PREFIX}-printeradmin "${DESTDIR}/${PREFIXSDIR}/bin/libreoffice${PRODUCTVERSION}-printeradmin"
 fi
 
 test "${PREFIX}" = libreofficedev${PRODUCTVERSION} && mime_def_file="libreofficedev${PRODUCTVERSION}.xml" || mime_def_file="libreoffice${PRODUCTVERSION}.xml"
-mkdir -p "${DESTDIR}/usr/share/mime/packages"
-cp openoffice.org.xml "${DESTDIR}/usr/share/mime/packages/$mime_def_file"
-chmod 0644 "${DESTDIR}/usr/share/mime/packages/$mime_def_file"
+mkdir -p "${DESTDIR}/${PREFIXSDIR}/share/mime/packages"
+cp openoffice.org.xml "${DESTDIR}/${PREFIXSDIR}/share/mime/packages/$mime_def_file"
+chmod 0644 "${DESTDIR}/${PREFIXSDIR}/share/mime/packages/$mime_def_file"
 
-mkdir -p "${DESTDIR}/usr/share/applications"
+mkdir -p "${DESTDIR}/${PREFIXSDIR}/share/applications"
 for i in `cat launcherlist`; do
-  ln -sf "${office_root}/share/xdg/${i}" "${DESTDIR}/usr/share/applications/${PREFIX}-${i}"
+  ln -sf "${office_root}/share/xdg/${i}" "${DESTDIR}/${PREFIXSDIR}/share/applications/${PREFIX}-${i}"
 done
 
