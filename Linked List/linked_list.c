#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
Roll No: 20CS8016
Q: Write an algorithm for inserting an element in a singly linked linear list before a node whose value is val. 
  Consider different possible scenarios for insertion: 
  (i) at the  beginning, 
  (ii) in the middle, 
  (iii) at the end or
  (iv) may not be inserted.
*/

struct node {
  int data;
  struct node * next_node;
};

struct node * head = NULL;


//
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


void insert_before(int number, int val) {

  struct node *newptr = (struct node *)malloc(sizeof(struct node));

  newptr -> data = number;

  if (head == NULL){
    insert_at_top(number);

  } else {
    struct node * current_node, * previous_node;
    current_node = head;
    previous_node = NULL;

    bool found = 0;

    while (current_node -> next_node != NULL){
      
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

  insert_before(69, 10);
  display_list();

  return 0;
}