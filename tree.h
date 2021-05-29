#ifndef __TREE__
#define __TREE__

typedef struct _tree_node {
  void* data;
  struct _tree_node* left;
  struct _tree_node* right;
  struct _tree_node* parent;
} TreeNode;

typedef struct _tree {
  TreeNode* root;
  int (*cmpFn)(void*, void*);
  int (*key_match)(void*, void*);
} Tree;

static TreeNode*
malloc_tree_node(void);

Tree*
init_tree(void);

void
register_cmpFn(Tree* tree, int (*cmpFn)(void*, void*));

void
register_tree_key_matchFn(Tree* tree, int (*key_matchFn)(void*, void*));

void
tree_insert(Tree* tree, void* data);

void
inorder_tree_walk(Tree* tree);

TreeNode*
tree_search(Tree* tree, void* key);

/* TreeNode* */
/* tree_min(Tree* tree); */

TreeNode*
tree_min(TreeNode* node);

/* TreeNode* */
/* tree_max(Tree* tree); */

TreeNode*
tree_max(TreeNode* node);

TreeNode*
tree_successor(TreeNode* tree); // get next node in sorted order

void
tree_delete(Tree* tree, void *data);

#endif
