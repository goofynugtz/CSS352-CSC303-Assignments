#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
Roll No:20CS8016

Q1. Write a C program to perform the following operations in a BST:
-	Insert a key value in a tree (iterative logic)
-	Insert a key value in a tree (recursive logic)
-	Delete a key value from the tree
-	Search a key value and return its node address (if found)
-	Traverse the tree
-	Display the depth of the tree
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


bool insertNodeIterative (tree * t, int value){
  node * root = t -> root;
  node * parent;
  node * n;

  if (root == NULL){
    t -> root = createNode(value);
    return 1;
  }

  while (root != NULL){
    if (root -> data == value){
      printf("\nError: Node already exists.\n");
      return 0;
    }
    
    parent = root;
    if (root -> data > value)
      root = root -> left;
    else
      root = root -> right;
  }

  n = createNode(value);
  if (parent -> data > value)
    parent -> left = n;
  else
    parent -> right = n;

  return 1;
}


bool insertNodeRecursive (tree * t, node * n, int value){
  if (n == NULL){
    t -> root = createNode(value);
    return 1;
  }

  if (value == n -> data){
    return 1;
  }

  if (value < n -> data){
    if (n -> left == NULL)
      n -> left = createNode(value);
    return (insertNodeRecursive(t, n -> left, value));
  
  } else {
    if (n -> right == NULL)
      n -> right = createNode(value);
    return (insertNodeRecursive(t, n -> right, value));
  }
}


bool deleteNode (tree * t, int value){
  
  node * previous;
  node * root = t -> root;

  while (root != NULL){
    if (value == root -> data)
      break;
    
    previous = root;
    if (value < root -> data)
      root = root -> left;
    else
      root = root -> right;
  }

  if (root == NULL)
    return 0;

  if (root -> left == NULL && root -> right == NULL){
    if (previous -> left == root)
      previous -> left = NULL;
    else
      previous -> right = NULL;
    free(root);
    return 1;
  }

  node * n;
  if (root -> left != NULL){
    n = root -> left;

    if (n -> right == NULL){
      root -> data = n -> data;
      root -> left = n -> left;
      free(n);
      return 1;
    }

    while (n -> right != NULL){
      previous = n;
      n = n -> right;
    }

    root -> data = n -> data;
    previous -> right = n -> left;
    free(n);
    return 1;
  }

  if (root -> right != NULL){
    n = root -> right;

    if (n -> left == NULL){
      root -> data = n -> data;
      root -> right = n -> right;
      free(n);
      return 1;
    }

    while (n -> left != NULL){
      previous = n;
      n = n -> left;
    }

    root -> data = n -> data;
    previous -> left = n -> right;
    free(n);
    return 1;
  }
}


node * searchNode (tree * t, int value){
  node * n = t -> root;

  while (n != NULL){
    if (value == n -> data)
      break;
    if (value < n -> data)
      n = n -> left;
    else if (value > n -> data)
      n = n -> right;
  }

  if (n == NULL){
    return NULL;
  }

  return n;
}


int depth (node * n){
  if (n == NULL)
    return 0;
  else {
    return __max(depth(n -> left) + 1, depth(n -> right) + 1);
  }
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


int main (){

  tree t;
  printf("\n");
  printf("1. Insert a #key (Iteratively)\n");
  printf("2. Insert a #key (Recursively)\n");
  printf("3. Delete a #key from tree\n");
  printf("4. Search for a #key\n");
  printf("5. Display Tree\n");
  printf("6. Display depth\n");
  printf("0. Exit\n");
  
  bool wantToExit = false;

  while (!wantToExit){
    printf("\nEnter Choice: ");
    int c; scanf("%d", &c);

    int value, height;
    bool inserted = false, deleted = false;

    switch (c){
      case 1:
        printf("\nEnter value to insert: ");
        scanf("%d", &value);
        inserted = insertNodeIterative(&t, value);

        if (inserted)
          printf(">> %d has been inserted.\n", value);
        else
          printf("Error: Insertion aborted.\n");
        break;

      case 2:
        printf("\nEnter value to insert: ");
        scanf("%d", &value);
        inserted = insertNodeRecursive(&t, t.root, value);

        if (inserted)
          printf(">> %d has been inserted.\n", value);
        else
          printf("Error: Insertion aborted.\n");
        break;

      case 3:
        printf("#Value to be deleted: ");
        scanf("%d", &value);
        deleted = deleteNode(&t, value);

        if (deleted)
          printf(">> %d has been deleted.\n", value);
        else
          printf("Error: Could not delete.\n");
        break;

      case 4:
        printf("Enter #value to search: ");
        scanf("%d", &value);
        node * search = searchNode(&t, value);

        if (search == NULL)
          printf("Could not find value.\n");
        else 
          printf(">> Requested Node is stored at %x\n", &(*search));
        break;

      case 5:
        printf("\n>> Inorder Traversal: ");
        inOrderTraversal(t.root);
        printf("\n>> Preorder Traversal: ");
        preOrderTraversal(t.root);
        printf("\n");
        break;

      case 6:
        printf(">> Height: %d\n", depth(t.root));
        break;

      default:
        wantToExit = 1;
        break;
    }
  }

  return 0;
}