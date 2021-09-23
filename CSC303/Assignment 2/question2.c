#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
/* Roll No: 20CS8016 

Q2: Write an algorithm for bubble sort using while loop. 
In case, the elements are sorted before the 
maximum number of possible passes/iterations, terminate the algorithm.
*/

int arr[10];

void bubble_sort(){
  int size = sizeof(arr)/sizeof(arr[0]);
  int counter = 1;

  while (counter < size){
    int index = 0;
    while (index < size - counter){
      if (arr[index] > arr[index+1]){
        int temp = arr[index];
        arr[index] = arr[index+1];
        arr[index+1] = temp;
      }
      index++;
    }
    counter++;
  }
}


int main () {
  srand(time(NULL)); //Seeds time as random function

  // printf("\nEnter %d numbers to be sorted: ");
  for (int i = 0; i < SIZE; i++){
    // scanf("%d", &arr[i]);
    arr[i] = rand() % 100; //Generates random int from 0 to 100
  }

  printf("\nRandomly generated array is: ");
  for (int i = 0; i < SIZE; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  bubble_sort();
  printf("\nSorted Array: ");
  for (int i = 0; (i) < SIZE; i++){
    printf("%d ", arr[i]);
  }
  printf("\n\n");

  return 0;
}