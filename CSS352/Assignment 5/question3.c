#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 5

/* 
Roll No: 20CS8016

Q3. Write a menu driven program in C to implement queue as an ADT using linked list   
  [Consider the following data structure operations during your implementation]. 
- ENQUEUE 
- DEQUEUE
- queueFRONT [Extract the information from FRONT of the queue]
- queueREAR [Extract the information from REAR of the queue]
- queueCOUNT [Return the number of elements in the queue]
- emptyQUEUE
- fullQUEUE
- DISPLAY [Display all the elements stored in a queue]
- destroyQUEUE [Delete all the data elements from the queue and release its memory, then deletes and release memory space for the head node pointer]
*/

typedef struct node {
  int data;
  struct node *next_node;
} node;

typedef struct queue {
  node *front, *rear;
  int size;
} queue;


queue * createQueue (){
  queue * q = (queue *) malloc(sizeof(queue));
  q -> front = NULL;
  q -> rear = NULL;
  q -> size = 0;
  return q;
}


node * insertNode (int value){
  node * _temp = (node *)malloc(sizeof(node));
  _temp -> data = value;
  _temp -> next_node = NULL;
  return _temp;
}


void enqueue (queue * q, int value){

  node * new_node = insertNode(value);

  q -> size++;
  if (q -> rear == NULL){
    q -> front = new_node;
    q -> rear = new_node;
    return;
  }

  q -> rear -> next_node = new_node;
  q -> rear = new_node;
}


void dequeue (queue * q){

  if (q -> front == NULL){
    printf("Error: \n");
    return;
  }

  q -> size--;
  node * _temp = q -> front;
  q -> front = q -> front -> next_node;

  if (q -> front == NULL){
    q -> rear = NULL;
  }

  free(_temp);
}


int queueFront (queue * q){
  if (q -> front == NULL){
    printf("Error: \n");
    return -1;
  }

  return q -> front -> data;
}

int queueRear (queue *q){
  if (q -> rear == NULL){
    printf("Error: \n");
    return -1;
  }

  return q -> rear -> data;
}


int queueCount (queue *q){
  return q -> size;
}


