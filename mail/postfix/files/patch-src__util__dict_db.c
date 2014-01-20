--- src/util/dict_db.c.orig	2014-01-19 16:47:50.460409194 -0600
+++ src/util/dict_db.c	2014-01-19 16:48:29.269797040 -0600
@@ -693,7 +693,7 @@
 	msg_fatal("set DB cache size %d: %m", dict_db_cache_size);
     if (type == DB_HASH && db->set_h_nelem(db, DICT_DB_NELM) != 0)
 	msg_fatal("set DB hash element count %d: %m", DICT_DB_NELM);
-#if DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR > 0)
+#if DB_VERSION_MAJOR == 6 || DB_VERSION_MAJOR == 5 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR > 0)
     if ((errno = db->open(db, 0, db_path, 0, type, db_flags, 0644)) != 0)
 	FREE_RETURN(dict_surrogate(class, path, open_flags, dict_flags,
 				   "open database %s: %m", db_path));
