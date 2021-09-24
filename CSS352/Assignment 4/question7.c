#include <stdio.h>
#include <stdbool.h>
#define SIZE 100
/* 
Roll No: 20CS8016

Q7. Write a program in C to test if a string is palindrome using STACK
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


void isPalindrome (char * word, stack * s) {
  create_stack(s);

  for (int i = 0; word[i] != '\0'; i++){
    push(s, word[i]);
  }

  bool flag = true;

  for (int i = 0; word[i] != '\0'; i++){
    if (word[i] != pop(s)){
      flag = 0;
      break;
    }
  }

  if (flag){
    printf("The word %s is a Palindrome!", word);
  } else {
    printf("The word %s is NOT a Palindrome.", word);
  }
}


int main (){

  char word[SIZE];
  printf("\nEnter word: ");
  scanf("%s", word);

  isPalindrome(word, &s);

  return 0;
}