#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 100

/* 
Roll No: 20CS8016

Q4. Write a C program for evaluating a postfix expression.
*/


typedef struct stack {
  int top;
  float items[SIZE];
} stack;

stack s;

void create_stack (stack *s){
  s -> top = -1;
}

bool isEmpty (stack *s){
  return s -> top == -1;
}

bool isOperand (char c){
  return c >= '0' && c <= '9';
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
    return '!';
  } else {
    return s -> items[s -> top--];
  }
}



void evalPostfix (char * string, stack * s){

  char postfix[SIZE];
  strcpy(postfix, string);

  float result;

  for (int i = 0; postfix[i]; i++){

    if (postfix[i] == ' ') continue;

    if (isOperand(postfix[i]))
      push(s, postfix[i] - '0');

    else if (isOperator(postfix[i])) {
      float a = pop(s);
      float b = pop(s);

      switch (postfix[i]){
        case '+':
          push(s, a + b);
          break;
        case '-': 
          push(s, b - a); 
          break;
        case '*': 
          push(s, a * b); 
          break;
        case '/': 
          push(s, b / a); 
          break;
        case '^':
          push(s, pow(b, a));
          break;
      }
    }
  }

  result = pop(s);
  printf("Result: %.3f", result);
}


int main (){
  create_stack(&s);
  char string[SIZE];
  printf("\nPostfix Expression: ");
  gets(string);

  evalPostfix(string, &s);

  return 0;
}