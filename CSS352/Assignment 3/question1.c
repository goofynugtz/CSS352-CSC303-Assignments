#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
Roll no: 20CS8016

Q1: Write a C program to find whether a specified element say, 
ITEM, is present in a given singly linked linear list or not. 
If the element ITEM is found, then report the position of ITEM within the list, 
else report "ITEM not found".
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


void create_list() {
  int n;
  struct node *ptr;

  printf("Number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements of the list: ");
  for (int i = 0; i < n; i++){

    int value;
    scanf("%d", &value);
    push(value);
  }
}


void search_for(int key) {

  struct node * ptr; 
  ptr = head;
  int index = 0; bool found = 0;

  if (ptr == NULL){
    printf("Empty List\n");
  } else {
    while (ptr != NULL){
      index++;
      if (ptr -> data == key){
        printf("Item %d is present in list at node %d\n", key, index);
        found = 1;
        break;
      }
      ptr = ptr -> next_node;
    }

    if (!found){
      printf("Item not found in list.\n");
    }
  }
}


int main () {

  create_list();

  int key;
  printf("Search for: ");
  scanf("%d", &key);
  search_for(key);

  return 0;
}