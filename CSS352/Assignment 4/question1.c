#include <stdio.h>
#define SIZE 100

/* 
Roll No: 20CS8016

Q1. Write a menu driven program in C to perform following data structure operations on stack 
using **array**:   
- CREATE 
- PUSH
- POP
- PEEK [Extract the information from top of the stack]
- PEEP [Extract ith information from top of the stack]
- UPDATE [Update ith information from the top of the stack]
- DISPLAY [Display all the elements stored in a stack]
*/

typedef struct list {
  int top;
  int items[SIZE];
} stack;

stack s;

void create_stack (stack *s) {
  s -> top = -1;
  printf("\nStack created successfully.\n");
}


void push (stack *s, int value) {
  if (s -> top >= SIZE) {

    printf ("\nError: Stack overflow\n");
    return;

  } else {

    s -> top++;
    s -> items[s -> top] = value;
  }
}


void pop (stack *s) {
  if (s -> top < 0) {
    printf ("\nError: Stack is already empty.\n");
    return;

  } else {
    printf("Popped Out: %s\n", s -> items[s -> top]);
    s -> top--;
  }
}


void peek (stack *s) {
  printf("Top of stack is: %d\n", s -> items[s -> top]);
}


void peep (stack *s, int i) {
  printf("Stack[%d]: %d\n", i, s -> items[i]);
}


void update (stack *s, int i, int updatedValue){
  int beforeValue = s -> items[i];
  s -> items[i] = updatedValue;
  printf("Updated: %d -> %d\n", beforeValue, updatedValue);
}


void display_stack (stack *s) {
  int size = s -> top;

  printf("Stack: ");
  for (int i = 0; i <= size; i++){
    printf("%d ", s -> items[i]);
  }
  printf("\n");
}

//Driver
int main () {

  create_stack(&s);
  // printf("1: Creating Stack\n");

  printf("\n");
  printf("1: Push Value into stack\n");
  printf("2: Pop from stack\n");
  printf("3: Peek [Top of stack]\n");
  printf("4: Peep [ith Element from top of stack]\n");
  printf("5: Update [ith Element from top of stack]\n");
  printf("6: Display Stack\n");
  printf("0: Exit Program\n");

  while (1){
    printf("\nChoose Option: ");

    int n;
    scanf("%d", &n);

    int i, value;

    switch (n)
    {
    case 1:
      printf("Enter #value to be inserted: ");
      scanf("%d", &value);
      push(&s, value);
      continue;

    case 2:
      pop(&s);
      continue;

    case 3:
      peek(&s);
      continue;

    case 4:
      printf("#i Index: ");
      scanf("%d", &i);
      peep(&s, i);
      continue;
    
    case 5:
      printf("Enter #index of element to be updated: ");
      scanf("%d", &i);
      printf("Enter #value: ");
      scanf("%d", &value);
      update(&s, i, value);
      continue;

    case 6:
      display_stack(&s);

    default:
      break;
    }


  }

  return 0;
}