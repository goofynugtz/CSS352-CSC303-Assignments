#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

/* 
Roll No: 20CS8016

Q2. Write a menu driven program in C to perform following data structure operations on stack 
using **linked list**. 
- CREATE 
- PUSH
- POP
- PEEK [Extract the information from top of the stack]
- PEEP [Extract ith information from top of the stack]
- UPDATE [Update ith information from the top of the stack]
- DISPLY [Display all the elements stored in a stack]
*/

typedef struct node {
	int data;
	struct node *next_node;
} node;

node * top = NULL;


void create_stack (){
	top = NULL;
	printf("\nStack created successfully.\n");
}


void push (int value){

  node *ptr = (node*)malloc(sizeof(node));   
  
  if(ptr == NULL) {  
    printf("Something went wrong in allocating space\n");   
  
  } else {

    ptr -> data = value;
    ptr -> next_node = top;  
    top = ptr;
  }
}


void pop (){

  node *ptr = top;

  if (ptr == NULL) {  
    printf("List is already Empty.\n");

  } else {

    int removedItem = top -> data;
    top = top -> next_node;
    free(ptr);
    printf("Popped Out: %s\n", removedItem);
  } 
}


void peek (){
  node *ptr = top;

  if (ptr == NULL) {  
    printf("List is Empty.\n");

  } else {

    printf("Top of Stack is: %d\n", top -> data);
  }
}


void peep (int i){
  node *ptr = top;

  if (ptr == NULL) {  
    printf("List is Empty.\n");

  } else {
    int index = 0;
    while (ptr != NULL){
      ptr = ptr -> next_node;
      index++;

      if (index == i){
        printf("Stack[%d]: %d\n", i, ptr -> data);
        break;
      }
    }
  }
}


void update (int i, int updatedValue){
  node *ptr = top;

  if (ptr == NULL) {  
    printf("List is Empty.\n");

  } else {
    int index = 0;
    while (ptr != NULL){
      ptr = ptr -> next_node;
      index++;

      if (index == i){
        int beforeValue = ptr -> data;
        ptr -> data = updatedValue;
        printf("Updated: %d -> %d\n", beforeValue, updatedValue);
      }
    }
  }
}


void display_stack (){
	int i;  
  node *ptr = top;  

  if(ptr == NULL){
    printf("Stack is empty\n");  
  } else {
    printf("Stack: ");  
    while(ptr != NULL){
      printf("%d ", ptr -> data);  
      ptr = ptr -> next_node;  
    }
    printf("\n");
  } 
}


//Driver
int main (){

  create_stack();

  printf("\n");
  printf("1: Push Value into stack\n");
  printf("2: Pop from stack\n");
  printf("3: Peek [Top of stack]\n");
  printf("4: Peep [ith Element from top of stack]\n");
  printf("5: Update [ith Element from top of stack]\n");
  printf("6: Display Stack\n");
  printf("0: Exit Program\n");

  bool wantToExit = 0;

  while (!wantToExit){
    printf("\nChoose Option: ");

    int n;
    scanf("%d", &n);

    int i, value;

    switch (n){
      
      case 1:
        printf("Enter #value to be inserted: ");
        scanf("%d", &value);
        push(value);
        break;

      case 2:
        pop();
        break;

      case 3:
        peek();
        break;

      case 4:
        printf("#i Index: ");
        scanf("%d", &i);
        peep(i);
        break;

      case 5:
        printf("Enter #index of element to be updated: ");
        scanf("%d", &i);
        printf("Enter #value: ");
        scanf("%d", &value);
        update(i, value);
        break;

      case 6:
        display_stack();
        break;

      default:
        wantToExit = 1;
        break;
    }
  }

  return 0;
}