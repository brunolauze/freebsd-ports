--- qtbase/src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp.orig	2013-10-13 20:05:44.504811401 -0500
+++ qtbase/src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp	2013-10-13 20:10:16.365060493 -0500
@@ -40,7 +40,7 @@
 ****************************************************************************/
 
 #include "qtablegenerator.h"
-
+#include <locale.h>
 #include <QtCore/QRegularExpression>
 #include <QtCore/QByteArray>
 #include <QtCore/QTextCodec>
