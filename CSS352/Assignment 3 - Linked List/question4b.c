#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Roll No: 20CS8016
Q: A linked list head is given which is sorted. 
Insert a given element in the list head so that after insertion, 
the list head is also sorted
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
    node * current_pointer = head;
    node * previous_pointer = NULL;

    if (current_pointer -> data >= newptr -> data) {
      newptr -> next_node = head;
      head = newptr;

    } else {

      while (current_pointer != NULL){
        if (current_pointer -> data >= newptr -> data){
          previous_pointer -> next_node = newptr;
          newptr -> next_node = current_pointer;
          return;

        } else {

          if (current_pointer -> next_node == NULL){
            current_pointer -> next_node = newptr;
            newptr -> next_node = NULL;
            return;
          }  
        }
        previous_pointer = current_pointer;
        current_pointer = current_pointer -> next_node;
      }
    }
  }
}


void display_list() {
  node * ptr; 
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

  //This will give a list in sorted manner.
  sorted_insertion(5);
  sorted_insertion(420);
  sorted_insertion(7);
  sorted_insertion(45);
  sorted_insertion(4);
  sorted_insertion(69);
  printf("\nSorted List: ");
  display_list();

  int n;
  printf("\nEnter a number to be inserted in list: ");
  scanf("%d", &n);
  sorted_insertion(n);

  printf("\nSorted List: ");
  display_list();

  return 0;
}