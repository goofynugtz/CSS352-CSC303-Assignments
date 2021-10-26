#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* 
Roll No: 20CS8016

Q3. A binary tree is given which is represented using a single array. 
Write a C program to convert the same tree into a linked structure. [OPTIONAL]
*/

typedef struct arrayTree {
  char * array;
  int size; //No. of nodes
} arrayTree;

typedef struct node {
  char data;
  struct node * leftChild, * rightChild;
} node;


// The random array generated is converted to linked tree structure
node * arrayToLinkedConverter (arrayTree * arrayTree, int index){

  if (index < (arrayTree -> size)){
    node * tree = (node *) malloc (sizeof(node));
    tree -> data = arrayTree -> array[index];
    tree -> leftChild = arrayToLinkedConverter(arrayTree, 2 * index + 1);
    tree -> rightChild = arrayToLinkedConverter(arrayTree, 2 * index + 2);
    
    return tree;
  } else {
    return NULL;
  }
}

arrayTree * randomArrayGenerator (int size){

  srand(time(NULL)); // Uses time as seed
  arrayTree * tree = (arrayTree *) malloc (sizeof(arrayTree));
  char * array = (char *) malloc (sizeof(char) * size);

  tree -> array = array;
  for (int i = 0; i < size; i++){
    array[i] = 'A' + (rand() % 26);
  }

  tree -> size = size;
  return tree;
}


void inorderTraversal (node * ptr){
  if (ptr != NULL){
    inorderTraversal(ptr -> leftChild);
    printf("%c ", ptr -> data);
    inorderTraversal(ptr -> rightChild);
  }
}


void orderedTraversal (node * ptr){
  if (ptr != NULL){
    printf("%c ", ptr -> data);
    orderedTraversal(ptr -> leftChild);
    orderedTraversal(ptr -> rightChild);
  }
}


int main (){

  int size;
  printf("\nEnter the size of array: ");
  scanf("%d", &size);

  arrayTree * arrayTree = randomArrayGenerator(size);
  printf("\nGenerated Array: ");
  for (int i = 0; i < arrayTree -> size; i++){
    printf("%c ", arrayTree -> array[i]);
  }
  printf("\n\n");

  node * root = arrayToLinkedConverter(arrayTree, 0);
  printf("Tree: \n");
  printf("Ordered Traversal: ");
  orderedTraversal(root);
  printf("\n");
  printf("Inordered Traversal: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}