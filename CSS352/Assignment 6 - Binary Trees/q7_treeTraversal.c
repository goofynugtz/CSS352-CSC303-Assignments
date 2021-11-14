#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
Roll No: 20CS8016

Q7. Write a C program to implement the three different tree traversal 
techniques (inorder, preorder and postorder) for a binary tree.
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


void inOrderTraversal (node * ptr){
  if (ptr != NULL){
    inOrderTraversal(ptr -> leftChild);
    printf("%s ", ptr -> data);
    inOrderTraversal(ptr -> rightChild);
  }
}

void preOrderTraversal (node * ptr){
  if (ptr != NULL){
    printf("%s ", ptr -> data);
    preOrderTraversal(ptr -> leftChild);
    preOrderTraversal(ptr -> rightChild);
  }
}

void postOrderTraversal (node * ptr){
  if (ptr != NULL){
    postOrderTraversal(ptr -> leftChild);
    postOrderTraversal(ptr -> rightChild);
    printf("%s ", ptr -> data);
  }
}


int main (){

  tree t;
  printf("\n\nFor choice:\n1: Yes\t2: No\n");

  t.root = createNode();
  createTree(t.root);

  printf("\n");
  printf("InOrder Traversal: ");
  inOrderTraversal(t.root);
  printf("\n");

  printf("PreOrder Traversal: ");
  preOrderTraversal(t.root);
  printf("\n");

  printf("PostOrder Traversal: ");
  postOrderTraversal(t.root);
  printf("\n");

  return 0;
}