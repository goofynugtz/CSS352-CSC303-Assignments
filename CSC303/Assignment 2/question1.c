#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

/* Roll No: 20CS8016 

Q1: Write an algorithm for sequential search using 
array having only a single comparison in the loop.
*/

void sequential_search(int arr[], int key){
  bool found = 0;

  for (int i = 0; i < SIZE; i++){
    if (arr[i] == key){
      found = true;
      printf("%d is found at position %d (Index: %d)\n", key, i+1, i);
    }
  }

  if (!found){
    printf("%d is not found in the array.\n", key);
  }
}

int main () {

  int arr[SIZE];
  printf("Enter %d elements of array: ", SIZE);
  for (int i = 0; i < SIZE; i++){
    scanf("%d", &arr[i]);
  }

  int key;
  printf("Value to be searched in array: ");
  scanf("%d", &key);
  sequential_search(arr, key);

  return 0;
}