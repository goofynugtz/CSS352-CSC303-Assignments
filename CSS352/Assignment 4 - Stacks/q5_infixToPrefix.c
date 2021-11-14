#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 100

/* 
Roll No: 20CS8016

Q5. Write a program for transforming an infix expression 
to a prefix expression.
*/

typedef struct stack {
  int top;
  int items[SIZE];
} stack;

stack s;

void create_stack (stack *s){
  s -> top = -1;
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
    return;
  } 
  else {
    s -> items[++(s -> top)] = value;
  }
}

char pop (stack *s){
  if (isEmpty(s)){
    return '\n';
  } else {
    return s -> items[s -> top--];
  }
}

char peek (stack *s){
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


void infixToPrefix (char * string, stack *s){
  //Reverse the string
  strrev(string);

  char infix[SIZE];
  char prefix[SIZE];

  memset(infix, '\0', SIZE);

  strcpy(infix, string);
  
  int i, j;
  for (i = 0, j = 0; infix[i]; i++){
    if (infix[i] == ' ')
      continue;

    //Operand
    if (isOperand(infix[i])){
      prefix[j++] = infix[i];
    }

    //Operator 
    else if (isOperator(infix[i])) {
      while (!isEmpty(s) && priority(infix[i]) < priority(peek(s)) && isOperator(peek(s))){
        prefix[j++] = pop(s);
      }
      push(s, infix[i]);
    }
    
    //Opening Parenthesis (Reversed)
    else if (infix[i] == ')'){
      push(s, infix[i]);
    }
    //Closing Parenthesis (Reversed)
    else if (infix[i] == '('){
      while (!isEmpty(s) && isOperator(peek(s))){
        prefix[j++] = pop(s);
      }

      if (!isEmpty(s) && peek(s) == ')'){
        pop(s);
      }
    }
  }

  while (!isEmpty(s)){
    prefix[j++] = pop(s);
  }
  prefix[j] = '\0';

  strrev(prefix);
  
  printf("\nPrefix Expression: %s\n\n", prefix);
}


int main (){
  create_stack(&s);
  char string[SIZE];
  printf("\nInfix Expression: ");
  gets(string);

  infixToPrefix(string, &s);

  return 0;
}