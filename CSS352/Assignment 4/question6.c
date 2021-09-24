#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

/* 
Roll No: 20CS8016

Q6. Write a program in C that takes one mathematical expression (in infix notation) and checks 
whether the opening and closing parenthesis match or not and print the correctness of the 
expression.
*/


typedef struct stack {
  int top;
  char items[SIZE];
} stack;

stack s;

void create_stack (stack *s){
  s -> top = -1;
}

bool isEmpty (stack *s){
  return s -> top == -1;
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


void eval (char * string, stack * s){
  create_stack(s);

  for (int i = 0; string[i] != '\0'; i++){
    if (string[i] == '(')
      push(s, string[i]);

    else if (string[i] == ')')
      pop(s);
  }

  if (!isEmpty(s)){
    printf("The expression was faulty at %d places\n", s -> top + 1);
  } else {
    printf("Expression is legitimate.\n");
  }
}


int main (){

  char string[SIZE];

  printf("\nMathematical Expression: ");
  gets(string);

  eval(string, &s);


  return 0;
}