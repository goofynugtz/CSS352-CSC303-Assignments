#include <stdio.h>

/* 
Roll No: 20CS8016

Q1. Write C-programs for Binary Search for both recursive and non-recursive versions.
*/

// Non-recursive
int nonRecBinarySearch (int * arr, int n, int key){
  int start = 0;
  int end = n;

  while (start <= end){
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
  int mid = start + (end - start)/2;

  if (arr[mid] == key)
    return mid;

  else if (arr[mid] > key)
    return recBinarySearch(arr, start, mid-1, key);

  else
    return recBinarySearch(arr, mid+1, end, key);

  return -1;
}

int main (){

  printf("\nEnter no. of elements in array: ");
  int n;
  scanf("%d", &n);

  int arr[n];
  printf(">> Enter sorted array \n");
  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("Enter the #key to search: ");
  int key;
  scanf("%d", &key);

  printf("\n:: Non-Recursive Binary Search: \n");
  int result = nonRecBinarySearch(arr, n, key);
  if (result != -1)
    printf(">> %d found at array[%d].\n", key, result);
  else
    printf(">> Not found.");

  printf("\n:: Recursive Binary Search: \n");
  result = recBinarySearch(arr, 0, n-1, key);
  if (result != -1)
    printf(">> %d found at array[%d].\n", key, result);
  else
    printf(">> Not found.");

  return 0;
}