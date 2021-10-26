#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
Roll No: 20CS8016

Q5. Considering linked list representation of a binary tree, 
write a C program that uses recursive functions to 
find the total number of nodes, number of edges and 
the maximum depth or height of a binary tree. 
[Hint: For height calculation, recursively calculate height 
of left and right subtrees of a node and assign height to 
the node as max of the heights of two children plus 1.]
*/

typedef struct node {
  char data;
  struct node * leftChild, * rightChild;
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
  newNode -> leftChild = NULL;
  newNode -> rightChild = NULL;
  return newNode;
}

void createTree (node * ptr){

  printf("%c -> Left Node? ", ptr -> data);
  int isLeftNode; scanf("%d", &isLeftNode);

  if (isLeftNode){
    node * left = createNode();
    ptr -> leftChild = left;
    createTree(left);
    printf("\n");
  } else {
    ptr -> leftChild = NULL;
  }

  printf("%c -> Right Node? ", ptr -> data);
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


int totalNumberOfNodes (node * root){
  if (root == NULL)
    return 0;

  else {
    return totalNumberOfNodes(root -> leftChild) 
    + totalNumberOfNodes(root -> rightChild) + 1;
  }
}


int maximumHeight (node * root){
  if (root == NULL)
    return 0;

  else {
    int left = maximumHeight(root -> leftChild);
    int right = maximumHeight(root -> rightChild);
    return (left > right) ? left + 1 : right + 1;
  }
}

int totalNumberOfEdges (node * root){
  return totalNumberOfNodes(root) - 1;
}


int main (){

  tree t;
  printf("\n\nFor choice:\n1: Yes\t2: No\n");

  t.root = createNode();
  createTree(t.root);

  printf(">> No. of nodes: %d\n", totalNumberOfNodes(t.root));
  printf(">> No. of edges: %d\n", totalNumberOfEdges(t.root));
  printf(">> Maximum Height: %d\n", maximumHeight(t.root));

  return 0;
}