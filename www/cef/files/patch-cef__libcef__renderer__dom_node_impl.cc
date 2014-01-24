--- cef/libcef/renderer/dom_node_impl.cc.orig	2014-01-23 14:38:59.063976748 -0600
+++ cef/libcef/renderer/dom_node_impl.cc	2014-01-23 14:39:27.464117056 -0600
@@ -112,8 +112,6 @@
       return DOM_NODE_TYPE_TEXT;
     case WebNode::CDataSectionNode:
       return DOM_NODE_TYPE_CDATA_SECTION;
-    case WebNode::EntityNode:
-      return DOM_NODE_TYPE_ENTITY;
     case WebNode::ProcessingInstructionsNode:
       return DOM_NODE_TYPE_PROCESSING_INSTRUCTIONS;
     case WebNode::CommentNode:
@@ -124,10 +122,6 @@
       return DOM_NODE_TYPE_DOCUMENT_TYPE;
     case WebNode::DocumentFragmentNode:
       return DOM_NODE_TYPE_DOCUMENT_FRAGMENT;
-    case WebNode::NotationNode:
-      return DOM_NODE_TYPE_NOTATION;
-    case WebNode::XPathNamespaceNode:
-      return DOM_NODE_TYPE_XPATH_NAMESPACE;
     default:
       return DOM_NODE_TYPE_UNSUPPORTED;
   }
