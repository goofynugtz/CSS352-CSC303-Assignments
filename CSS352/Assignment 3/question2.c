#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
Roll No: 20CS8016

2. Write a C program for inserting an element in a singly linked linear list head,
before a node whose data value is val. 
Consider the different possible scenarios for insertion
• at the beginning,
• in the middle,
• at the end,
• list may be empty, or
• may not be required to insert.
*/

struct node {
  int data;
  struct node * next_node;
};

struct node * head = NULL;


//CASE: 1. Inserts at the beggining of list
void insert_at_top(int value) {
  struct node *newptr = (struct node*)malloc(sizeof(struct node));
  newptr -> data = value;
  newptr -> next_node = head;
  head = newptr;
}


//CASE: 3. Pushes value to the end of list
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


//CASE: 2. Inserts before given val
void push_before(int number, int val) {

  struct node *newptr = (struct node *)malloc(sizeof(struct node));
  newptr -> data = number;

  if (head == NULL){
    insert_at_top(number);

  } else {
    struct node * current_node, * previous_node;
    current_node = head;
    previous_node = NULL;

    if (current_node -> data == val){
      insert_at_top(number);

    } else {

      bool found = 0;
      while (current_node != NULL){

        if (current_node -> data != val){
          previous_node = current_node;
          current_node = current_node -> next_node;

        } else if (current_node -> data == val){
          previous_node -> next_node = newptr;
          newptr -> next_node = current_node;

          found = 1;
          break;
        }
      }

      if (!found) {
        push(number);
      }
    }
  }
}


//CASE: 4.Does not insert if val is not found
void not_push_before_if_not_found(int number, int val) {

  struct node *newptr = (struct node *)malloc(sizeof(struct node));
  newptr -> data = number;

  if (head == NULL){
    insert_at_top(number);

  } else {
    struct node * current_node, * previous_node;
    current_node = head;
    previous_node = NULL;

    if (current_node -> data == val){
      insert_at_top(number);

    } else {

      bool found = 0;
      while (current_node != NULL){

        if (current_node -> data != val){
          previous_node = current_node;
          current_node = current_node -> next_node;

        } else if (current_node -> data == val){
          previous_node -> next_node = newptr;
          newptr -> next_node = current_node;

          found = 1;
          break;
        }
      }

      if (!found) {
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
    printf("List: ");
    while (ptr != NULL){
      printf("%d ", ptr -> data);
      ptr = ptr -> next_node;
    }
    printf("\n");
  }
}


int main () {

  create_list();
  // display_list();
  int n;
  printf("Number to be inserted: ");
  scanf("%d", &n);

  int val;
  printf("Number in list to pushed before: ");
  scanf("%d", &val);
  // push_before(n, val);
  not_push_before_if_not_found(n, val);

  display_list();

  return 0;
}