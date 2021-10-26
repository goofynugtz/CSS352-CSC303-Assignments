#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
Roll No: 20CS8016

Q2. Write a C program to implement the following operations on a binary tree 
- Insert a new node as a leaf node
- Delete a specified leaf node.
*/

typedef struct node {
  char data;
  struct node * leftChild, * rightChild;
} node;

typedef struct tree {
  node * root;
} tree;


node * createNode (char value){
  node * newNode = (node *) malloc (sizeof(node));
  newNode -> data = value;

  newNode -> leftChild = NULL;
  newNode -> rightChild = NULL;
  return newNode;
}


node * searchNode(node * root, int value){
  if (root == NULL)
    return NULL;

  if (root -> data != value){
    node * temp = searchNode(root -> leftChild, value);
    if (temp == NULL)
      return searchNode(root -> rightChild, value);    
    else
      return temp;

  } else
    return root;
}


void insertNode(node * root, int key, char value){

  if (root == NULL){
    printf(">> No tree???\n");
    return;
  }
  
  node * ptr = searchNode(root, key);
  if (ptr == NULL){
    printf("Key not found.\n");
    return;
  }

  // If both child nodes are empty
  if (ptr -> leftChild == NULL && ptr -> rightChild == NULL){
    printf("Insert at left or right? (L/R): ");
    char choice;
    fflush(stdin);
    scanf("%c", &choice);

    if (choice == 'L' || choice == 'l'){
      ptr -> leftChild = createNode(value);
    } else if (choice == 'R' || choice == 'r'){
      ptr -> rightChild = createNode(value);
    }
  
  // When only left child is empty 
  } else if (ptr -> leftChild == NULL && ptr -> rightChild != NULL){
    printf(">> RightNode is not empty. Insert at left? (Y/N) ");
    char choice;
    fflush(stdin);
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y'){
      ptr -> leftChild = createNode(value);
    } else 
      return;

  // When only right child is empty
  } else if (ptr -> rightChild == NULL && ptr -> leftChild != NULL){
    printf(">> LeftNode is not empty. Insert at Right? (Y/N) ");
    char choice;
    fflush(stdin);
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y'){
      ptr -> rightChild = createNode(value);
    } else 
      return;
  
  // No child is empty
  } else 
    printf("Error: No child node is empty.");

}


node * searchParent (node * root, int value){
  if (root == NULL)
    return NULL;
  
  if ((root -> leftChild != NULL && root -> leftChild -> data == value)
  || (root -> rightChild != NULL && root -> rightChild -> data == value))
    return root;
  
  else {
    node * temp = searchParent( root -> leftChild, value);
    if (temp == NULL)
      return searchParent(root -> rightChild, value);
    else
      return temp;
  }
}


void deleteNode (node * root, int value){

  if (root == NULL)
    printf("Tree is empty.\n");
  
  node * parent = searchParent(root, value);
  if (parent == NULL)
    printf("Error: Parent is null.\n");
  
  else {
    node * ptr1 = parent -> leftChild;
    node * ptr2 = parent -> rightChild;

    if (ptr1 -> data == value){

      if (ptr1 -> leftChild == NULL && ptr1 -> rightChild == NULL){
        free(ptr1);
        parent -> leftChild = NULL;
        printf(">> Item deleted.\n");
      } else 
        printf("Error: Node has non-empty children.\n");
      
    } else {

      if (ptr2 -> leftChild == NULL && ptr2 -> rightChild == NULL){
        free(ptr2);
        parent -> rightChild = NULL;
        printf("Item deleted.\n");
      } else 
        printf("Error: Node has non-empty children.\n");
    }
  }
}

void inorderedTraversal (node * ptr){
  if (ptr != NULL){
    inorderedTraversal(ptr -> leftChild);
    printf("%c ", ptr -> data);
    inorderedTraversal(ptr -> rightChild);
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

  tree t;

  bool wantToExit = false;
  printf("Creating root node...\n");

  char value;
  printf("Enter root value: ");
  fflush(stdin);
  scanf("%c", &value);
  
  t.root = createNode(value);

  printf("\nPress\n");
  printf("1: Insert node\n");
  printf("2: Delete Node\n");
  printf("3: Display Tree\n");
  printf("0: Exit\n");

  while (!wantToExit){
    printf("\nEnter option: ");
    fflush(stdin);
    int n; scanf("%d", &n);
    char value, key;

    switch (n){
      case 1:
        printf("\nEnter #char for node: ");
        fflush(stdin);
        scanf("%c", &value);

        printf("Enter #key where node is to be placed: ");
        fflush(stdin);
        scanf("%c", &key);

        insertNode(t.root, key, value);
        break;

      case 2:
        printf("\nEnter the value to delete: ");
        fflush(stdin);
        scanf("%c", &value);
        deleteNode(t.root, value);
        break;

      case 3:
        printf("\n");
        printf("Ordered Traversal: ");
        orderedTraversal(t.root);
        printf("\n");
        printf("Inordered Traversal: ");
        inorderedTraversal(t.root);
        printf("\n");
        break;

      default:
        wantToExit = true;
        break;
    }
  }

  return 0;
}