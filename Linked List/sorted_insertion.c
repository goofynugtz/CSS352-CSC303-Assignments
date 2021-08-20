#include <stdio.h>
#include <stdlib.h>

/*
Roll No: 20CS8016
Q: Write a function to insert an element in a linked list in sorted order. 
The function will be called for every element to be inserted.
*/


typedef struct node
{
  int data;
  struct node* next_node;
} node;

node * head = NULL;


void sorted_insertion(int value) {
  struct node *newptr = (struct node*)malloc(sizeof(struct node));
  newptr -> data = value;

  if (head == NULL){
    newptr -> next_node = NULL;
    head = newptr;

  } else {
    node * ptr = head;
    if (ptr -> data < newptr -> data) {

      node * temp = ptr -> next_node;
      ptr -> next_node = newptr;
      newptr -> next_node = temp;

    } else {

      newptr -> next_node = ptr;
      head = newptr;
    }
    
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

  sorted_insertion(5);
  sorted_insertion(7);
  sorted_insertion(6);
  sorted_insertion(4);

  display_list();

  return 0;
}