#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Roll No: 20CS8016

Q3: Write a C program for deletion of an element from a singly linked linear list
head before a node whose data value is val. 
Consider different possible scenarios for deletion. 
*/

struct node {
  int data;
  struct node * next_node;
};

struct node * head = NULL;


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


void delete_before(int val) {
  struct node * previous_node = head;
  struct node * current_node = previous_node -> next_node;
  struct node * forward_node = current_node -> next_node;

  if (previous_node == NULL){
    printf("Nothing in the list to be deleted.\nList is already Empty\n");
  } else {

    bool found = 0;
    if (previous_node -> data == val){
      printf("There's no value before %d in list.\n", val);
      found = 1;
      return;
    } else if (current_node -> data == val) {
      found = 1;
      head = current_node;
      free(previous_node);
      return;
    } else {

      while (forward_node != NULL){
        if (forward_node -> data == val){
          found = 1;
          previous_node -> next_node = current_node -> next_node;
          free(current_node);
          return;
        }
        previous_node = current_node;
        current_node = forward_node;
        forward_node = forward_node -> next_node;
      }

      if (!found){
        printf("Value not found in list.\n");
        return;
      }
    }
  }
}


void create_list() {
  int n;
  struct node *ptr;
  printf("Enter the no. of elements to enter: ");
  scanf("%d", &n);
  printf("Enter the elements below\n");
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
    printf("\nList: ");
    while (ptr != NULL){
      printf("%d ", ptr -> data);
      ptr = ptr -> next_node;
    }
    printf("\n");
  }
}


int main () {

  create_list();
  
  int val;
  printf("\nNumber before to be deleted: ");
  scanf("%d", &val);
  delete_before(val);
  display_list();
  
  return 0;
}