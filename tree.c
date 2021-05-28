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

TreeNode*
tree_min(Tree* tree) {
  if(tree == NULL || tree->root == NULL)
    return NULL;
  
  TreeNode* node = tree->root;

  while(node->left != NULL)
    node = node->left;

  return node;
}

TreeNode*
tree_max(Tree* tree) {
  if(tree == NULL || tree->root == NULL)
    return NULL;

  TreeNode* node = tree->root;

  while(node->right != NULL)
    node = node->right;

  return node;
}


