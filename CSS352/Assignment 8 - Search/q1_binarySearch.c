#include <stdio.h>

/* 
Roll No: 20CS8016

Q1. Write C-programs for Binary Search for both recursive and 
non-recursive versions.
*/

// Non-recursive
int nonRecBinarySearch (int * arr, int n, int key, int * c){
  int start = 0;
  int end = n;

  (*c) = 0;
  while (start <= end){

    (*c)++;
    int mid = start + (end - start)/2;

    if (arr[mid] == key)
      return mid;

    else if (arr[mid] > key)
      end = mid - 1;

    else 
      start = mid + 1;
  }
  
  return -1;
}

// Recursive
int recBinarySearch (int * arr, int start, int end, int key){
  if (end >= start){
    int mid = start + (end - start)/2;

  if (arr[mid] == key)
    return mid;

  else if (arr[mid] > key)
    return recBinarySearch(arr, start, mid-1, key);

  else
    return recBinarySearch(arr, mid+1, end, key);
  }

  return -1;
}

int main (){

  printf("\nEnter no. of elements in array: ");
  int n;
  scanf("%d", &n);

  int arr[n];
  printf("\n>> Enter array (in Ascending Order)\n");
  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("\nEnter the #key to search: ");
  int key; int c;
  scanf("%d", &key);

  printf("\n:: Non-Recursive Binary Search: \n");
  int result = nonRecBinarySearch(arr, n, key, &c);
  if (result != -1)
    printf(">> %d found at array[%d].\n>> %d comparisions.\n", key, result, c);
  else
    printf(">> Not found.\n>> Made %d comparisions.\n", c);

  printf("\n:: Recursive Binary Search: \n");
  result = recBinarySearch(arr, 0, n-1, key);
  if (result != -1)
    printf(">> %d found at array[%d].\n", key, result);
  else
    printf(">> Not found.");

  return 0;
}