#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
Roll No: 20CS8016

Q1. Write a C program to create a binary tree of n nodes with data values as 
A, B, C, …., where n should be the user input. The user will have the full freedom 
to organize the nodes in the binary tree as per his/her choice.
*/

typedef struct node {
  char data[2];
  struct node * leftChild, * rightChild;
} node;

typedef struct tree {
  node * root;
} tree;


node * createNode (){
  node * newNode = (node *) malloc (sizeof(node));
  printf("\nEnter #char for node: ");
  char value[2];
  scanf("%s", value);
  newNode -> data[0] = value[0];
  newNode -> data[1] = '\0';

  newNode -> leftChild = NULL;
  newNode -> rightChild = NULL;
  return newNode;
}


void createTree (node * ptr){

  printf("%s -> Left Node? ", ptr -> data);
  int isLeftNode; scanf("%d", &isLeftNode);

  if (isLeftNode){
    node * left = createNode();
    ptr -> leftChild = left;
    createTree(left);
    printf("\n");
  } else {
    ptr -> leftChild = NULL;
  }

  printf("%s -> Right Node? ", ptr -> data);
  int isRightNode; scanf("%d", &isRightNode);
  
  if (isRightNode){
    node * right = createNode();
    ptr -> rightChild = right;
    createTree(right);
    printf("\n");
  } else {
    ptr -> rightChild = NULL;
  }
}


void inorderTraversal (node * ptr){
  if (ptr != NULL){
    inorderTraversal(ptr -> leftChild);
    printf("%s ", ptr -> data);
    inorderTraversal(ptr -> rightChild);
  }
}


void orderedTraversal (node * ptr){
  if (ptr != NULL){
    printf("%s ", ptr -> data);
    orderedTraversal(ptr -> leftChild);
    orderedTraversal(ptr -> rightChild);
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
  inorderTraversal(t.root);
  printf("\n");

  return 0;
}