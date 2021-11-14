#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
Roll No: 20CS8016

Q2. Given the inorder and postorder traversal sequence, 
Write a C program to construct the binary tree.
*/

typedef struct node {
  int data;
  struct node * left, * right;
} node;

typedef struct tree {
  node * root;
} tree;

node * createNode (int value){
  node * n = (node *) malloc (sizeof(node));
  n -> data = value;
  n -> left = NULL;
  n -> right = NULL;
  return n;
}


node * construct (int * inorder, int start, int end, int * postorder, int * index){
  node * root = createNode(postorder[(*index)]);
  (*index)--;
  int i;
  for (i = start; i >= end; i--)
    if (inorder[i] == root -> data)
      break;

  if (i < start)
    root -> right = construct(inorder, start, i+1, postorder, index);
  if (i > end)
    root -> left = construct(inorder, i-1, end, postorder, index);

  return root;
}

node * constructTreeWithPostOrder (int * inorder, int * postorder, int n){
  int index = n-1;
  return construct(inorder, n-1, 0, postorder, &index);
}


void inOrderTraversal (node * ptr){
  if (ptr != NULL){
    inOrderTraversal(ptr -> left);
    printf("%d ", ptr -> data);
    inOrderTraversal(ptr -> right);
  }
}

void preOrderTraversal (node * ptr){
  if (ptr != NULL){
    printf("%d ", ptr -> data);
    preOrderTraversal(ptr -> left);
    preOrderTraversal(ptr -> right);
  }
}

void postOrderTraversal (node * ptr){
  if (ptr != NULL){
    postOrderTraversal(ptr -> left);
    postOrderTraversal(ptr -> right);
    printf("%d ", ptr -> data);
  }
}


int main (){

  int inorder[] = {4, 2, 1, 7, 5, 8, 3, 6};
	// int preorder[] = {1, 2, 4, 3, 5, 7, 8, 6};
  int postorder[] = {4, 2, 7, 8, 5, 6, 3, 1};
  int n = sizeof(inorder) / sizeof(inorder[0]);

  node * root = constructTreeWithPostOrder(inorder, postorder, n);

  printf("\n>> Inorder Traversal: ");
  inOrderTraversal(root);
  printf("\n");
  printf("\n>> Preorder Traversal: ");
  preOrderTraversal(root);
  printf("\n");
  printf("\n>> Postorder Traversal: ");
  postOrderTraversal(root);
  printf("\n");

  return 0;
}