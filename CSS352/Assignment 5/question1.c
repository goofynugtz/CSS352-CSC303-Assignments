#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

/* 
Roll No: 20CS8016

Q1. Write a menu driven program in C to perform following data structure operations on linear queue using array. 
- ENQUEUE 
- DEQUEUE
- queueFRONT [Extract the information from FRONT of the queue]
- queueREAR [Extract the information from REAR of the queue]
- queueCOUNT [Return the number of elements in the queue]
- DISPLAY [Display all the elements stored in a queue]
*/


typedef struct queue {
  int front, rear;
  int array[SIZE];
} queue;

queue q;

void createQueue (queue *q){
  q -> front = 0;
  q -> rear = 0;
}

bool isFull (queue *q){
  return (q -> rear == SIZE - 1);
}

bool isEmpty (queue *q){
  return (q -> rear == q -> front);
}

int queueFront (queue *q){
  if (isEmpty(q)){
    printf("Error: Queue is Empty\n");
    return -1;
  }
  return q -> array[q -> front];
}

int queueRear (queue *q){
  if (isEmpty(q)){
    printf("Error: Queue is Empty\n");
    return -1;
  }
  return q -> array[q -> rear];
}

int queueCount (queue *q){
  return (q -> rear - q -> front);
}



void enqueue (queue *q, int value){

  if (isFull(q)){
    printf("Error: Overflow\n");
    return;
  }
  q -> array[q -> rear++] = value;
}

void enqueueMultiple (queue *q){
  if (isFull(q)){
    printf("Error: Overflow\n");
    return;
  }

  printf("Enter the number of elements to be enqueued: ");
  int x; scanf("%d", &x);

  if (x > SIZE - (q -> rear)){
    printf("Not enough space available.\n");
    printf("Free Space: %d\n", SIZE - queueCount(q));
  } else {
    printf("Enter #values below\n");
    for (int i = 0; i < x; i++){
      int value; scanf("%d", &value);
      enqueue(q, value);
    }
  }
}


void dequeue (queue *q){
  if (isEmpty(q)){
    printf("Error: Queue is empty.\n");
    return;
  }
  printf(">> %d has been removed\n", queueFront(q));
  q -> front++;

  if (q -> front == q -> rear){
    q -> front = 0;
    q -> rear = 0;
  }
}




void displayQueue (queue *q){\

  printf("Queue: ");
  for (int i = q -> front; i < q -> rear; i++){
    printf("%d ", q -> array[i]);
  }
  printf("\n");
}


int main (){

  createQueue(&q);

  printf("\n");
  printf("1: Insert / Enqueue\n");
  printf("2: Insert / Enqueue multiple elements\n");
  printf("3: Delete / Dequeue\n");
  printf("4: Front of Queue\n");
  printf("5: Rear of Queue\n");
  printf("6: No. of elements in queue\n");
  printf("7: All elements of queue\n");
  printf("0: Exit Program\n");

  bool wantToExit = 0;

  while (!wantToExit){
    printf("\nChoose Option: ");

    int n; scanf("%d", &n);

    int value;

    switch (n){
      case 1:
        if (isFull(&q)){
          printf("Error: Queue is full\n");
          break;

        } else {

          printf("Enter #value to be pushed: ");
          scanf("%d", &value);
          enqueue(&q, value);
          break;
        }

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
        displayQueue(&q);
        break;

      default:
        wantToExit = true;
        break;
    }
  }

  return 0;
}