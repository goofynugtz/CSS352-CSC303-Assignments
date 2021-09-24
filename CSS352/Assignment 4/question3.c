#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 100

/* 
Roll No: 20CS8016

Q3. Write a C program for transforming an infix expression to a postfix expression.
*/

typedef struct stack {
  int top;
  int items[SIZE];
} stack;

stack s;

void create_stack (stack *s){
  s -> top = -1;
  // printf("\nStack created successfully.\n");
}

bool isEmpty (stack *s){
  return s -> top == -1;
}

bool isOperand (char c){
  return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

bool isOperator (char c){
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void push (stack *s, int value){
  if (s -> top >= SIZE) {
    // printf ("\nError: Stack overflow\n");
    return;
  } 
  else {
    s -> items[++(s -> top)] = value;
  }
}

char pop (stack *s){
  if (isEmpty(s)){
    // printf ("\nError: Stack is already empty.\n");
    return '!';
  } else {
    // printf("Popped Out: %s\n", s -> items[s -> top]);
    return s -> items[s -> top--];
  }
}

char peek (stack *s){
  // printf("Top of stack is: %d\n", s -> items[s -> top]);
  return s -> items[s -> top];
}


int priority (char c){
  if (c == '+' || c == '-')
    return 1;

  if (c == '*' || c == '/')
    return 2;

  if (c == '^')
    return 3;

  return -1;
}


void infixToPostfix (char * string, stack *s){
  push(s, '(');

  char infix[SIZE];
  char postfix[SIZE];

  memset(infix, '\0', SIZE);

  strcpy(infix, string);
  strcat(infix, ")");
  
  int i, j;
  for (i = 0, j = 0; infix[i]; i++){
    if (infix[i] == ' ')
      continue;

    //Operand
    if (isOperand(infix[i])){
      postfix[j++] = infix[i];
    }

    //Operator 
    else if (isOperator(infix[i])) {
      while (!isEmpty(s) && priority(infix[i]) <= priority(peek(s)) && isOperator(peek(s))){
        postfix[j++] = pop(s);
      }
      push(s, infix[i]);
    }
    
    //Opening Parenthesis
    else if (infix[i] == '('){
      push(s, infix[i]);
    }
    //Closing Parenthesis
    else if (infix[i] == ')'){
      while (!isEmpty(s) && isOperator(peek(s))){
        postfix[j++] = pop(s);
      }

      if (!isEmpty(s) && peek(s) == '('){
        pop(s);
      }
    }
    
  }

  while (!isEmpty(s)){
    postfix[j++] = pop(s);
  }
  postfix[j] = '\0';
  
  printf("\nPostfix Expression: %s\n\n", postfix);
}


int main (){
  create_stack(&s);
  char string[SIZE];
  printf("\nInfix Expression: ");
  scanf("%s", string);

  infixToPostfix(string, &s);

  return 0;
}