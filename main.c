#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct person {
  char name[30];
  unsigned int age;
  int id;
} Person;

int
cmp_person_by_id(void* p1, void* p2);

void
inorder_walk2(TreeNode* root);

int
person_key_match(void* data, void* key);

void
print_person_data(TreeNode* node);

int main(int argc, char **argv) {
  Tree* tree = init_tree();
  register_cmpFn(tree, cmp_person_by_id);
  
  Person* p1 = (Person*)malloc(sizeof(Person));
  
  strncpy(p1->name, "Eugene", strlen("Eugene")+1);
  p1->age = 23;
  p1->id = 1;

  Person* p2 = (Person*)malloc(sizeof(Person));
  strncpy(p2->name, "Alina", strlen("Alina")+1);
  p2->age = 23;
  p2->id = 2;

  Person* p3 = (Person*)malloc(sizeof(Person));
  strncpy(p3->name, "Marina", strlen("Marina")+1);
  p3->age = 50;
  p3->id = 3;

  Person* p4 = (Person*)malloc(sizeof(Person));
  strncpy(p4->name, "Malhaz", strlen("Malhaz")+1);
  p4->age = 50;
  p4->id = 0;

  Person* p5 = (Person*)malloc(sizeof(Person));
  strncpy(p5->name, "Olya", strlen("Olya")+1);
  p5->age = 22;
  p5->id = 9;

  Person* p6 = (Person*)malloc(sizeof(Person));
  strncpy(p6->name, "Nastya", strlen("Nastya")+1);
  p6->age = 23;
  p6->id = 7;

  Person* p7 = (Person*)malloc(sizeof(Person));
  strncpy(p7->name, "Katya", strlen("Katya")+1);
  p7->age = 23;
  p7->id = 8;

  tree_insert(tree, p1);
  tree_insert(tree, p3);
  tree_insert(tree, p5);
  tree_insert(tree, p6);
  tree_insert(tree, p7);
  tree_insert(tree, p2);
  
  /* inorder_walk2(tree->root); */
  /* printf("\n\n"); */
  /* register_tree_key_matchFn(tree, person_key_match); */
  /* TreeNode* search1 = tree_search(tree,(void*) 7); */

  /* Person* searchp1 = (Person*)search1->data; */
  /* printf("Node: %p Parent: %p Left: %p Right: %p\nId: %d\n\n", */
  /* 	 search1, search1->parent, search1->left, search1->right, searchp1->id); */

  //Tree* tmp = tree;
  
  printf("Tree min:\n");
  TreeNode* min = tree_min(tree);
  Person* min_p = (Person*)min->data;
  printf("Node: %p Parent: %p Left: %p Right: %p\nId: %d\n\n",
	 min, min->parent, min->left, min->right, min_p->id);

  printf("Tree max:\n");
  TreeNode* max = tree_max(tree);
  Person* max_p = (Person*)max->data;
  printf("Node: %p Parent: %p Left: %p Right: %p\nId: %d\n\n",
	 max, max->parent, max->left, max->right, max_p->id);

  
  return 0;
}

void
inorder_walk2(TreeNode* node) {
  if(node != NULL) {
    inorder_walk2(node->left);
    Person* person = (Person*)node->data;
    printf("Node: %p Parent: %p Left: %p Right: %p\nId: %d\n\n",
	   node, node->parent, node->left, node->right, person->id);
    inorder_walk2(node->right);
  }
}

void
print_person_data(TreeNode* node) {
  Person* person = (Person*)node->data;
  printf("Node: %p Parent: %p Left: %p Right: %p\nId: %d",
	 node, node->parent, node->left, node->right, person->id);
}

int
person_key_match(void* data, void* key) {
  Person* p = (Person*) data;
  int k = (int) key;

  if(p->id < k)
    return -1;
  else if(p->id > k)
    return 1;
  else
    return 0;
}

int
cmp_person_by_id(void* p1, void* p2) {
  if(p1 == NULL || p2 == NULL)
    assert(0);
  
  Person* data1 = (Person*) p1;
  Person* data2 = (Person*) p2;

  if(data1->id < data2->id)
    return -1;
  else if(data1->id > data2->id)
    return 1;
  else // equal
    return 0;
}
