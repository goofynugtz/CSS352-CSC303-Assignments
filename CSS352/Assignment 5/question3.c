#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
- fullQUEUE (Not Possible)
- DISPLAY [Display all the elements stored in a queue]
- destroyQUEUE [Delete all the data elements from the queue and release its memory, 
  then deletes and release memory space for the head node pointer]
*/

typedef struct node {
  int data;
  struct node * next;
} node;

typedef struct queue {
  node * front, * rear;
  int size;
} queue;

// emptyQueue
bool isEmpty (queue *q){
  return (q -> size == 0);
}

node * insertNode (int value){
  node * _temp = (node *)malloc(sizeof(node));
  _temp -> data = value;
  _temp -> next = NULL;
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

  q -> rear -> next = new_node;
  q -> rear = new_node;
}


void enqueueMultiple (queue *q){

  printf("Enter the number of elements to be enqueued: ");
  int x; scanf("%d", &x);

  printf("Enter #values below\n");
  for (int i = 0; i < x; i++){
    int value; scanf("%d", &value);
    enqueue(q, value);
  }
}


int dequeue (queue * q){

  if (isEmpty(q)){
    printf("Error: Queue is empty.\n");
    return -1;
  }

  int dequeuedVal;
  q -> size--;
  node * _temp = q -> front;
  dequeuedVal = _temp -> data;
  q -> front = q -> front -> next;
  free(_temp);
  if (q -> front == NULL){
    q -> rear = NULL;
  }
  printf(">> %d has been removed\n", dequeuedVal);
  return dequeuedVal;
}


int queueFront (queue * q){
  if (q -> front == NULL){
    printf("Error: Queue is Empty.\n");
    return -1;
  }

  return q -> front -> data;
}


int queueRear (queue *q){
  if (q -> rear == NULL){
    printf("Error: Queue is Empty.\n");
    return -1;
  }

  return q -> rear -> data;
}


int queueCount (queue *q){
  return q -> size;
}

void destroyQueue (queue * q){
  while (!isEmpty(q)){
    dequeue(q);
  }
}


void displayQueue (queue *q){\

  int i;
  node * ptr = q -> front;

  if (ptr == NULL){
    printf(">> Queue is empty.\n");
  } else {
    printf("Queue: ");
    while (ptr != NULL){
      printf("%d ", ptr -> data);
      ptr = ptr -> next;
    }
    printf("\n");
  }
}


int main (){

  queue q;
  q.front = NULL;
  q.rear = NULL;
  q.size = 0;

  printf("\n");
  printf("1: Insert / Enqueue\n");
  printf("2: Insert / Enqueue multiple elements\n");
  printf("3: Delete / Dequeue\n");
  printf("4: Front of Queue\n");
  printf("5: Rear of Queue\n");
  printf("6: No. of elements in queue\n");
  printf("7: All elements of queue\n");
  printf("8: Destroy Queue\n");
  printf("0: Exit Program\n");

  bool wantToExit = 0;

  while (!wantToExit){
    printf("\nChoose Option: ");

    int n; scanf("%d", &n);

    int value;

    switch (n){
      case 1:
        printf("Enter #value to be pushed: ");
        scanf("%d", &value);
        enqueue(&q, value);
        break;

      case 2:
        enqueueMultiple(&q);
        break;

      case 3:
        dequeue(&q);
        break;

      case 4:
        printf("Queue -> [Front]: ");
        printf("%d\n", queueFront(&q));
        break;

      case 5:
        printf("Queue -> [Rear]: ");
        printf("%d\n", queueRear(&q));
        break;

      case 6:
        printf("No. of items: ");
        printf("%d\n", queueCount(&q));
        break;

      case 7:
        if (isEmpty(&q))
          printf(">> Queue is Empty.\n");
        else  
          displayQueue(&q);
        break;

      case 8:
        destroyQueue(&q);
        break;

      default:
        wantToExit = true;
        break;
    }
  }
  return 0;
}