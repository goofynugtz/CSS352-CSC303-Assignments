#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
Roll No:20CS8016

Q3. Given values ‘x’ & ‘y’ write a C code to find the 
Lowest Common Ancestor (LCA) node of two key values 
‘x’ & ‘y’ in a BST.  
[Hint: you may try to write a recursive algorithm; the trick is 
to find such a node which has one of the keys in the left subtree 
and the other in the right subtree while descending down from the
root node]
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
void insertNode (tree * t, int value){
  node * root = t -> root;
  node * previous;

  if (root == NULL){
    t -> root = createNode(value);
    return;
  }

  while (root != NULL){
    if (root -> data == value){
      printf("\nError: Node already exists.\n");
      return;
    }
    
    previous = root;

    if (root -> data > value)
      root = root -> left;
    else
      root = root -> right;
  }

  node * n = createNode(value);

  if (previous -> data > value)
    previous -> left = n;
  else
    previous -> right = n;
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

node * lowestCommonAncestor (tree * t, node * n, int x, int y){
  if (x < n -> data && y < n -> data)
    return lowestCommonAncestor(t, n -> left, x, y);
  else if (x > n -> data && y > n -> data)
    return lowestCommonAncestor(t, n -> right, x, y);
  else 
    return n;
}


int main (){

  tree t;
  printf("\n");
  printf("1. Insert a #key\n");
  printf("2. Insert multiple #values\n");
  printf("3. Get Lowest Common Ancestor\n");
  printf("0: Exit\n");

  bool wantToExit = false;

  while (!wantToExit){
    printf("\nEnter Choice: ");
    int c; scanf("%d", &c);

    int value, n, x, y;

    switch (c){
      case 1:
        printf("\nEnter value to insert: ");
        scanf("%d", &value);
        insertNode(&t, value);
        printf(">> %d has been inserted.\n", value);
        break;

      case 2:
        printf("\nEnter no. of elements to insert: ");
        scanf("%d", &n);
        printf("Enter #values below\n");
        for (int i = 0; i < n; i++){
          scanf("%d", &value);
          insertNode(&t, value);
        }
        break;

      case 3:
        printf("\n#x #y: ");
        scanf("%d %d", &x, &y);
        node * checkX = searchNode(&t, x);
        if (!checkX){
          printf("Error: #x:%d is not found in the tree\n", x);
          break;
        }
        node * checkY = searchNode(&t, y);
        if (!checkY){
          printf("Error: #y:%d is not found in the tree\n", y);
          break;
        }
        node * ancestor = lowestCommonAncestor(&t, t.root, x, y);
        printf(">> %d is the Lowest Common Ancestor.\n", ancestor -> data);
        break;

      default:
        wantToExit = 1;
        break;
    }
  }


  return 0;
}