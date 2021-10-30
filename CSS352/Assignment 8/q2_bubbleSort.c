#include <stdio.h>
#include <stdbool.h>
/* 
Roll No: 20CS8016

Q2. Write a C program for Bubble Sort such that the number of comparasions it will always take is as less as possible
*/

void bubbleSort (int * arr, int n, int * swap){
  
  int counter = 1; *swap = 0;
  while (counter < n){

    for (int i = 0; i < n - counter; i++){
      if (arr[i] > arr[i+1]){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        (*swap)++;
      }
    }
    counter++;
    if ((*swap) == 0)
      break;
  }
}


int main (){

  printf("\nEnter no. of elements in array: ");
  int n;
  scanf("%d", &n);

  int arr[n];
  printf(">> Enter array \n");
  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  int swap = 0;
  bubbleSort(arr, n, &swap);

  printf("\n>> Bubble Sorted Array: ");
  for (int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("Swaps: %d\n", swap);

  return 0;
}
