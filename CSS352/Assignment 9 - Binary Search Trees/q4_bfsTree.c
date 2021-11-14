#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10010

/* 
Roll No: 20CS8016

Q4. Given a binary tree display it’s key sequence following 
breadth first search (bfs). 
[Hint: use queue data structure]
*/

typedef struct node {
  char data;
  struct node * left, * right;
} node;

typedef struct tree {
  node * root;
} tree;

node ** createQueue (int * front, int * rear){
  node ** queue = (node **) malloc (sizeof(node *) * SIZE);
  * front = * rear = 0;
  return queue; 
}

void enqueue(node ** queue, int * rear, node * new_node){
  queue[*rear] = new_node;
  (*rear)++;
}

node * dequeue(node ** queue, int * front){
  (*front)++;
  return queue[*front - 1];
}


void breadthFirstTraversal (node * root){
  int front, rear;
  node ** queue = createQueue(&front, &rear);
  node * current = root;

  while (current != NULL){
    fflush(stdin);
    printf("%c ", current -> data);

    if (current -> left)
      enqueue(queue, &rear, current -> left);

    if (current -> right)
      enqueue(queue, &rear, current -> right);
    
    current = dequeue(queue, &front);
  }
}


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


int main (){

  tree t;
  t.root = createNode();
  createTree(t.root);
  printf(">> Breadth Traversal: ");
  breadthFirstTraversal(t.root);
  printf("\n");

  return 0;
}