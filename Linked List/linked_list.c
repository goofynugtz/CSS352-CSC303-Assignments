#include <stdio.h>
#include <stdlib.h>

/* 
Roll No: 20CS8016
Q: Implementation of a Linked List.
*/

struct node {
  int data;
  struct node * next_node;
};

struct node * head = NULL;


void insert_at_top(int value) {
  
  struct node *newptr = (struct node*)malloc(sizeof(struct node));

  newptr -> data = value;
  newptr -> next_node = head;
  head = newptr;
}


void push(int value) {

  struct node *newptr = (struct node*)malloc(sizeof(struct node));

  newptr -> data = value;

  if (head == NULL){
    newptr -> next_node = NULL;
    head = newptr;

  } else {
    struct node * temp;
    temp = head;

    while (temp -> next_node != NULL){
      temp = temp -> next_node;
    }

    temp -> next_node = newptr;
    newptr -> next_node = NULL;
  }
}


void create_list() {
  int n;
  struct node *ptr;

  printf("Enter the no. of elements to enter: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++){

    int value;
    scanf("%d", &value);
    push(value);

  }

}


void display_list() {

  struct node * ptr; 
  ptr = head;

  if (ptr == NULL){
    printf("Empty List\n");
  } else {
    while (ptr != NULL){
      printf("%d ", ptr -> data);
      ptr = ptr -> next_node;
    }

    printf("\n");
  }
}

int main () {

  create_list();
  insert_at_top(5);
  push(6);
  push(3);
  push(8);
  display_list();

  return 0;
}