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

static void
recursive_walk(TreeNode* root);

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
/* recursive_tree_search(TreeNode* root, int key); */

#endif
