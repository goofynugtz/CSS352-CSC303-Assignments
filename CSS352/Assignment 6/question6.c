#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
Roll No: 20CS8016

Q6. Consider two binary trees T1 and T2. 
Write a C program to merge two binary trees.
[Hint: The entire tree T2 (or T1) can be 
merged as a subtree of T1 (or T2). 
This requires a null subtree in either or both trees.] 
*/

typedef struct node {
  char data;
  struct node * left, * right;
} node;

typedef struct tree {
  node * root;
} tree;


node * createNode (){
  node * newNode = (node *) malloc (sizeof(node));
  printf("\nEnter #char for node: ");
  char value;
  fflush(stdin);
  scanf("%c", &value);
  newNode -> data = value;

  newNode -> left = NULL;
  newNode -> right = NULL;
  return newNode;
}


void createTree (node * ptr){

  printf("%c -> Left Node? ", ptr -> data);
  int isLeftNode; scanf("%d", &isLeftNode);

  if (isLeftNode){
    node * left = createNode();
    ptr -> left = left;
    createTree(left);
    printf("\n");
  } else {
    ptr -> left = NULL;
  }

  printf("%c -> Right Node? ", ptr -> data);
  int isRightNode; scanf("%d", &isRightNode);
  
  if (isRightNode){
    node * right = createNode();
    ptr -> right = right;
    createTree(right);
    printf("\n");
  } else {
    ptr -> right = NULL;
  }
}


node * mergeTrees (node * t1, node * t2){

  if(t1 == NULL && t2 == NULL){
    printf(">> Both Trees Are Empty! Nothing to be merged.\n");
    return NULL;
  }
  if(t1 == NULL)
    return t2;
  
  if(t2 == NULL)
    return t1;
  
  if(t1 -> left == NULL){
    t1 -> left = t2;
    return t1;
  }
  else if(t1 -> right == NULL){
    t1 -> right = t2;
    return t1;
  }
  else if(t2 -> left == NULL){
    t2 -> left = t1;
    return t2;
  } 
  else if(t2 -> right == NULL){
    t2 -> right = t1;
    return t2;
  } 
  else {
    printf("\nError: nMerging is not possible!");
    return NULL;
  }
}


void inorderTraversal (node * ptr){
  if (ptr != NULL){
    inorderTraversal(ptr -> left);
    printf("%c ", ptr -> data);
    inorderTraversal(ptr -> right);
  }
}

void orderedTraversal (node * ptr){
  if (ptr != NULL){
    printf("%c ", ptr -> data);
    orderedTraversal(ptr -> left);
    orderedTraversal(ptr -> right);
  }
}


int main (){

  tree t1, t2;

  printf("\nFor choice:\n1: Yes\t2: No\n");

  printf("\n>> Enter values for Tree 1 ::");
  t1.root = createNode();
  createTree(t1.root);

  printf("\n>> Enter values for Tree 2 ::");
  t2.root = createNode();
  createTree(t2.root);

  printf("\nTree 1:\n");
  printf("Ordered Traversal: ");
  orderedTraversal(t1.root);
  printf("\n");
  printf("Inordered Traversal: ");
  inorderTraversal(t1.root);
  printf("\n");

  printf("\nTree 2:\n");
  printf("Ordered Traversal: ");
  orderedTraversal(t2.root);
  printf("\n");
  printf("Inordered Traversal: ");
  inorderTraversal(t2.root);
  printf("\n");

  node * mergedTree = mergeTrees(t1.root, t2.root);

  printf("\nMerged Tree:\n");
  printf("Ordered Traversal: ");
  orderedTraversal(mergedTree);
  printf("\n");
  printf("Inordered Traversal: ");
  inorderTraversal(mergedTree);
  printf("\n");

  return 0;
}