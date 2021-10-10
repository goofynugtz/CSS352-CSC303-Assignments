#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 10

/* 
Roll No: 20CS8016

Q4. Given a stack S and a queue Q, write procedures FILLQ_WITHS 
which will empty the contents of the stack S and 
insert them into the queue Q and FILLS_WITHQ which 
will fill the stack S with the elements deleted from the queue Q. 
Implement the procedures with S and Q having an array representation
*/

// Circular Queue
typedef struct queue {
  int front, rear;
  int size;
  int array[SIZE];
} queue;

queue q;

void createQueue (queue *q){
  q -> front = -1;
  q -> rear = -1;
  q -> size = 0;
}

bool isQueueFull (queue *q){
  return (q -> size == SIZE);
}

bool isQueueEmpty (queue *q){
  return (q -> size == 0);
}


int queueCount (queue *q){
  return (q -> size);
}


void enqueue (queue *q, int value){

  if (isQueueFull(q)){
    printf("Error: Enqueue Overflow\n");
    return;
  }

  if (q -> front == -1) q -> front = 0;
  q -> rear = (q -> rear + 1) % SIZE;
  q -> size++;
  q -> array[q -> rear] = value;
}


void enqueueMultiple (queue *q){
  if (isQueueFull(q)){
    printf("\nError: Queue is full.\n");
    return;
  }

  printf("Enter the number of elements to be enqueued: ");
  int x; scanf("%d", &x);

  if (x > SIZE - queueCount(q)){
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


int dequeue (queue *q){
  if (isQueueEmpty(q)){
    printf("Error: Queue is empty.\n");
    return -1;
  }

  int value = q -> array[q -> front];
  if (q -> front == q -> rear){
    q -> front = -1;
    q -> rear = -1;
    q -> size = 0;
  } else {
    q -> front = (q -> front + 1) % SIZE;
    q -> size--;
  }
  return value;
}

void displayQueue (queue *q){\

  int i;
  if (isQueueEmpty(q)){
    printf(">> Queue is empty.\n");
    return;
  }
  printf("Queue: ");
  for (i = q -> front; i != q -> rear; i = (i+1) % SIZE){
    printf("%d ", q -> array[i]);
  }
  printf("%d ", q -> array[i]);
  printf("\n");
}



// Stack
typedef struct stack {
  int top;
  int size;
  int items[SIZE];
} stack;

stack s;

void createStack (stack *s){
  s -> top = -1;
}

bool isStackEmpty (stack * s){
  return (s -> size == 0);
}

bool isStackFull (stack * s){
  return (s -> size == SIZE);
}

void push (stack *s, int value){
  if (isStackFull(s)) {
    printf ("\nError: Stack overflow\n");
    return;
  } else {
    s -> items[++(s -> top)] = value;
    s -> size++;
  }
}

void pushMutiple (stack *s){
  int x;
  printf("No. of values to be inserted in stack: ");
  scanf("%d", &x);

  if (x > SIZE - (s -> size)){
    printf("Not enough space available.\n");
    printf("Free Space: %d\n", SIZE - (s -> size));
  } else {
    printf("Enter values below >>\n");
    for (int i = 0; i < x; i++){
      int n;
      scanf("%d", &n);
      push(s, n);
    }
  }
}

int pop (stack *s){
  int popped; 
  if (isStackEmpty(s)){
    printf ("\nError: Stack is empty.\n");
    return -1;
  } else {
    popped = s -> items[s -> top];
    s -> top--;
    s -> size--;
  }

  return popped;
}


void displayStack (stack *s){
  int size = s -> top;

  if (isStackEmpty(s)){
    printf(">> Stack is empty.\n");
    return;
  }
  printf("Stack: ");
  for (int i = 0; i <= size; i++){
    printf("%d ", s -> items[i]);
  }
  printf("\n");
}


void fillQueueWithStack (queue * q, stack * s){
  printf("Stack ");
  while (!isStackEmpty(s) || !isQueueFull(q)){
    enqueue(q, pop(s));
    printf("->> ");
  }
  printf("Queue\n");
}

void fillStackWithQueue (stack * s, queue * q){
  printf("Queue ");
  while (!isQueueEmpty(q) || !isStackFull(s)){
    push(s, dequeue(q));
    printf("->> ");
  }
  printf("Stack\n");
}


int main (){

  createQueue(&q);
  createStack(&s);

  int n;
  printf("\n");
  printf("1: Push multiple elements into stack.\n");
  printf("2: Enqueue multiple elements into queue.\n");
  printf("\nChoose Option: ");
  scanf("%d", &n);

  switch (n){
    case 1:
      pushMutiple(&s);
      break;

    case 2:
      enqueueMultiple(&q);
      break;
  }

  printf("\n\n");
  printf("1: Fill Stack with Queue\n");
  printf("2: Fill Queue with Stack\n");
  printf("3: Push multiple elements to stack\n");
  printf("4: Push into stack\n");
  printf("5: Enqueue multiple elements\n");
  printf("6: Enqueue\n");
  printf("7: Display Stack\n");
  printf("8: Display Queue\n");
  printf("9: Exit\n");

  bool wantToExit = false;
  while (!wantToExit){

    int m;
    printf("\nChoose Option: ");
    scanf("%d", &m);

    int value;

    switch (m){
      case 1:
        if (isQueueEmpty(&q))
          printf(">> Queue is Empty\n");
        else
          fillStackWithQueue(&s, &q);
        break;

      case 2:
        if (isStackEmpty(&s))
          printf(">> Stack is Empty\n");
        else
          fillQueueWithStack(&q, &s);
        break;

      case 3:
        pushMutiple(&s);
        break;
      
      case 4:
        if (isStackFull(&s))
          printf(">> Stack is full\n");
        else {
          printf("Enter #value: ");
          scanf("%d", &value);
          push(&s, value);
        }
        break;

      case 5:
        enqueueMultiple(&q);
        break;

      case 6:
        if (isQueueFull(&q))
          printf(">> Queue is Full\n");
        else {
          printf("Enter #value: ");
          scanf("%d", &value);
          enqueue(&q, value);
        }
        break;

      case 7:
        displayStack(&s);
        break;
      
      case 8:
        displayQueue(&q);
        break;

      default:
        wantToExit = true;
        break;
    }
  }

  return 0;
}