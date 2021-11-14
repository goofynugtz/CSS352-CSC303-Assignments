#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* 
Roll No: 20CS8016

Q4. Repeat problem 3 when a given binary tree is represented 
with a linked structure. Write C program to build the same 
tree which will be stored in an array of suitable size. [OPTIONAL]
*/

typedef struct node {
  char data;
  struct node * left, * right;
} node;

typedef struct tree {
  node * root;
} tree;

char array[10000];


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


void insertToArray (node * root, int index){
  if (root == NULL)
    return;
  
  array[index] = root -> data;

  if (root -> left != NULL && root -> right != NULL){
    insertToArray(root -> left, 2 * index + 1);
    insertToArray(root -> right, 2 * index + 2);
  } else if (root -> left == NULL && root -> right != NULL){
    insertToArray(root -> right, 2 * index + 2);
  } else if (root -> right == NULL && root -> left != NULL){
    insertToArray(root -> left, 2 * index + 1);
  } else 
    return;
}


int totalNumberOfNodes (node * root){
  if (root == NULL)
    return 0;

  else {
    return totalNumberOfNodes(root -> left) 
    + totalNumberOfNodes(root -> right) + 1;
  }
}


void inorderedTraversal (node * ptr){
  if (ptr != NULL){
    inorderedTraversal(ptr -> left);
    printf("%c ", ptr -> data);
    inorderedTraversal(ptr -> right);
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
  tree t;
  printf("\n\nFor choice:\n1: Yes\t2: No\n");

  t.root = createNode();
  createTree(t.root);

  printf("\n");
  printf("Ordered Traversal: ");
  orderedTraversal(t.root);
  printf("\n");
  printf("Inordered Traversal: ");
  inorderedTraversal(t.root);
  printf("\n");

  int nodes = totalNumberOfNodes(t.root);
  insertToArray(t.root, 0);
  printf("Nodes: %d\n", nodes);

  printf("Converted Array: \n");
  for (int i = 0; i < 2 * nodes + 2; i++){
    printf("%c ", array[i]);
  }
  printf("\n");

  return 0;
}