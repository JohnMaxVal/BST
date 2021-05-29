#include "tree.h"
#include <stdlib.h>

Tree*
init_tree(void) {
  Tree* tree = (Tree*)malloc(sizeof(Tree));
  tree->root = NULL;
  return tree;
}

void
register_cmpFn(Tree* tree, int (*cmpFn)(void*, void*)) {
  tree->cmpFn = cmpFn;
}

void
register_tree_key_matchFn(Tree* tree, int (*key_matchFn)(void*, void*)) {
  tree->key_match = key_matchFn;
}

void
tree_insert(Tree* tree, void* data) {
  if(tree == NULL || data == NULL)
    return;
  
  TreeNode* tmp = NULL;
  TreeNode* root = tree->root;
  while(root != NULL) {
    tmp = root;
    if(tree->cmpFn(data, root->data) == -1)
      root = root->left;
    else
      root = root->right;
  }

  TreeNode* new = malloc_tree_node();
  new->data = data;
  new->parent = tmp;

  if(tmp == NULL)
    tree->root = new;
  else if(tree->cmpFn(new->data, tmp->data) == -1)
    tmp->left = new;
  else
    tmp->right = new;
}

static TreeNode*
malloc_tree_node(void) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->data = NULL;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;
}

TreeNode*
tree_search(Tree* tree, void* key) {
  if(tree == NULL)
    return NULL;

  TreeNode* node = tree->root;

  while(node != NULL && tree->key_match(node->data, key) != 0)
    if(tree->key_match(node->data, key) == -1)
       node = node->right;
    else
      node = node->left;

  return node;
}

/* TreeNode* */
/* tree_min(Tree* tree) { */
/*   if(tree == NULL || tree->root == NULL) */
/*     return NULL; */
  
/*   TreeNode* node = tree->root; */

/*   while(node->left != NULL) */
/*     node = node->left; */

/*   return node; */
/* } */

TreeNode*
tree_min(TreeNode* node) {
  while(node->right != NULL)
    node = node->right;
  return node;
}

TreeNode*
tree_max(TreeNode* node) {
  while(node->left != NULL)
    node = node->left;
  return node;
}

/* TreeNode* */
/* tree_max(Tree* tree) { */
/*   if(tree == NULL || tree->root == NULL) */
/*     return NULL; */

/*   TreeNode* node = tree->root; */

/*   while(node->right != NULL) */
/*     node = node->right; */

/*   return node; */
/* } */

void
tree_delete(Tree* tree, void* data) {
  TreeNode* node = tree_search(tree, data);

  TreeNode* tmp = NULL;
  
  if(node->left == NULL || node->right == NULL)
    tmp = node;
  else
    tmp = tree_successor(node);

  TreeNode* tmp2 = NULL;
  
  if(tmp->left != NULL)
    tmp2 = tmp->left;
  else
    tmp2 = tmp->right;

  if(tmp2 != NULL)
    tmp2->parent = tmp->parent;
  
  if(tmp->parent == NULL)
    tree->root = tmp2;
  else {
    if(tmp == tmp->parent->left)
       tmp->parent->left = tmp2;
    else
      tmp->parent->right = tmp2;
  }

  if(tmp != node) 
    node->data = tmp->data;

  free(tmp);
}

TreeNode*
tree_successor(TreeNode* node) {
  if(node == NULL)
    return NULL;
  
  if(node->right != NULL)
    return tree_min(node->right);

  TreeNode* parent = node->parent;

  while(parent != NULL && node == parent->right) {
    node = parent;
    parent = parent->parent;
  }

  return parent;
}

