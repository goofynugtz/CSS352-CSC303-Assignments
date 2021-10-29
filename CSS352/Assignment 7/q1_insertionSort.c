#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Roll No: 20CS8016

Q1. Write a C-program for insertion sort using a singly linked linear list. 
For this puspose, you use a function as described below, 
which will be called repeatedly from the main function. 
So, initially the output will be a null list. 
Insert an element in a sorted singly linked linear 
list such that after insertion the list will also be sorted.
*/

typedef struct node {
  int data;
  struct node * next;
} node;

typedef struct list {
  node * head;
} list;


void sorted_insertion(list * list, int value) {
  node * newNode = (node *) malloc (sizeof(node));
  newNode -> data = value;

  if (list -> head == NULL){
    newNode -> next = NULL;
    list -> head = newNode;

  } else {
    node * current = list -> head;
    node * previous = NULL;
    
    if (current -> data >= newNode -> data) {

      newNode -> next = list -> head;
      list -> head = newNode;

    } else {
      while (current != NULL){

        if (current -> data >= newNode -> data){
          previous -> next = newNode;
          newNode -> next = current;
          return;

        } else {

          if (current -> next == NULL){
            current -> next = newNode;
            newNode -> next = NULL;
            return;
          }  
        }
        previous = current;
        current = current -> next;
      }
    }
  }
}


void display_list(list * list) {

  node * ptr; 
  ptr = list -> head;

  if (ptr == NULL){
    printf("Empty List\n");
  } else {
    while (ptr != NULL){
      printf("%d ", ptr -> data);
      ptr = ptr -> next;
    }
    printf("\n");
  }
}


int main () {

  list l;

  bool wantToExit = false;
  printf("\n\n");
  printf("1: Insert single element\n");
  printf("2: Insert multiple elements\n");
  printf("3: Display list\n");
  printf("0: Exit\n");

  while (!wantToExit){

    int n;
    printf("\nEnter Choice: ");
    scanf("%d", &n);

    int value; int size;

    switch (n){
    case 1:
      printf("\nEnter #value: ");
      scanf("%d", &value);
      sorted_insertion(&l, value);
      printf(">> Inserted %d\n", value);
      break;

    case 2:
      printf("\nNo. of elemetns to be inserted: ");
      scanf("%d", &size);
      printf("Enter #values below\n");
      for (int i = 0; i< size; i++){
        scanf("%d", &value);
        sorted_insertion(&l, value);
      }
      break;

    case 3:
      printf("\nList: ");
      display_list(&l);
      break;
    
    default:
      wantToExit = 1;
      break;
    }
  }

  // sorted_insertion(5);
  // sorted_insertion(420);
  // sorted_insertion(7);
  // sorted_insertion(6);
  // sorted_insertion(4);
  // sorted_insertion(69);


  return 0;
}