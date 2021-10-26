#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/* 
Roll No:20CS8016

Q8. Given a postfix expression, write a program to construct an expression tree.
*/

typedef struct treeNode {
  char data;
  struct treeNode * left;
  struct treeNode * right;
} treeNode;

typedef struct stackNode {
  treeNode * data;
  struct stackNode * next;
} stackNode;

typedef struct stack {
  stackNode * top;
} stack;


bool isOperator (char c){
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}


void push (stack * s, treeNode * value){
  if (s == NULL)
    return;

  stackNode * ptr = (stackNode *) malloc (sizeof(stackNode));

  if (ptr == NULL)
    printf("Error: Stack node could not be allocated.\n");
  
  ptr -> data = value;
  ptr -> next = s -> top;
  s -> top = ptr;
}


treeNode * pop (stack * s){
  if (s == NULL)
    return NULL;

  if (s -> top == NULL){
    printf(">> Stack is empty.\n");
    return NULL;
  }

  treeNode * value = s -> top -> data;
  stackNode * temp = s -> top;
  s -> top = s -> top -> next;
  free(temp);
  return value;
}


treeNode * createNode (char c){
  treeNode * newNode = (treeNode *) malloc (sizeof(treeNode));
  newNode -> data = c;
  newNode -> left = NULL;
  newNode -> right = NULL;
  return newNode;
}


treeNode * expressionTree (char * expression, int n, stack * s){
  int index = 0;

  while (index != n){
    char c = expression[index];

    if (!isOperator(c)){
      treeNode * ptr = createNode(c);
      push(s, ptr);

    } else {
      treeNode * root = createNode(c);
      root -> right = pop(s);
      root -> left = pop(s);
      push(s, root);
    }

    index++;
  }
  return pop(s);
}


void inorderTraversal (treeNode * ptr){
  if (ptr != NULL){
    inorderTraversal(ptr -> left);
    printf("%c ", ptr -> data);
    inorderTraversal(ptr -> right);
  }
}


void orderedTraversal (treeNode * ptr){
  if (ptr != NULL){
    printf("%c ", ptr -> data);
    orderedTraversal(ptr -> left);
    orderedTraversal(ptr -> right);
  }
}


int main (){

  stack s;
  s.top = NULL;

  char expression[100];
  printf("\nEnter expression: ");
  scanf("%s", expression);

  int sizeOfExpression = strlen(expression);

  treeNode * root = expressionTree(expression, sizeOfExpression, &s);

  printf("\nOrdered Traversal: ");
  orderedTraversal(root);
  printf("\n");
  printf("Inordered Traversal: ");
  inorderTraversal(root);
  printf("\n");


  return 0;
}