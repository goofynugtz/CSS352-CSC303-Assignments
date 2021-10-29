#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
Roll No: 20CS8016

Q2. Given a singly linked linear list, write a C-program 
for making a list which is reverse of the given list
*/

typedef struct node {
  int data;
  struct node * next;
} node;

typedef struct list {
  node * head;
  int size;
} list;


void push(list * list, int value) {

  node * newptr = (node *) malloc(sizeof(node));
  newptr -> data = value;
  list -> size++;
  if (list -> head == NULL){
    newptr -> next = NULL;
    list -> head = newptr;
  } else {
    node * temp;
    temp = list -> head;

    while (temp -> next != NULL){
      temp = temp -> next;
    }
    temp -> next = newptr;
    newptr -> next = NULL;
  }
}


void reverseList (list * list){
  node * previous = NULL;
  node * current = list -> head;
  node * forward;

  while (current != NULL){
    forward = current -> next;
    current -> next = previous;
    previous = current;
    current = forward;
  }

  list -> head = previous;
}


void display_list(list * list) {
  node * ptr;
  ptr = list -> head;
  if (ptr == NULL){
    printf("Empty List\n");
  } else {
    printf("List: ");
    while (ptr != NULL){
      printf("%d ", ptr -> data);
      ptr = ptr -> next;
    }
    printf("\n");
  }
}


int main (){

  list l; l.head = NULL;

  int size;
  printf("\nEnter number of items to insert: ");
  scanf("%d", &size);

  printf(">> Enter items below\n");
  for (int i = 0; i < size; i++){
    int value;
    scanf("%d", &value);
    push(&l, value);
  }

  // push(&l, 1);
  // push(&l, 2);
  // push(&l, 3);
  // push(&l, 4);
  // push(&l, 5);

  printf("\n>> Original ");
  display_list(&l);

  reverseList(&l);

  printf("\n>> Reversed ");
  display_list(&l);

  return 0;
}