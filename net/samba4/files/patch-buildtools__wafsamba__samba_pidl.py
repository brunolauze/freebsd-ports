--- buildtools/wafsamba/samba_pidl.py.orig	2013-12-27 10:46:33.696677788 -0600
+++ buildtools/wafsamba/samba_pidl.py	2013-12-27 10:47:41.303482187 -0600
@@ -88,7 +88,7 @@
     # prime the list of nodes we are dependent on with the cached pidl sources
     t.allnodes = pidl_src_nodes
 
-    t.env.PIDL = os.path.join(bld.srcnode.abspath(), 'pidl/pidl')
+    t.env.PIDL = os.path.join('%%LOCALBASE%%', 'pidl/pidl')
     t.env.OPTIONS = TO_LIST(options)
     t.env.OUTPUTDIR = bld.bldnode.name + '/' + bld.path.find_dir(output_dir).bldpath(t.env)
 
