#include <stdio.h>
#include <stdbool.h>
/* 
Roll No: 20CS8016
Write a program in C to implement insertion, deletion and traversal (search) of an element from an array.
*/

int arr[15];


void insert_at(int index, int value){

  if(!arr[index]){
    arr[index] = value;
  } else {

    for (int i = sizeof(arr)/sizeof(arr[0]) - 1; i > index; i--){
      arr[i] = arr[i - 1];
    }

    arr[index] = value;
  }
}


void delete_from(int index){
  if(!arr[index]){
    printf("Index %d is already empty\n", index);
  } else {

    for (int i = index; i < sizeof(arr)/sizeof(arr[0]); i++){
      arr[i] = arr[i + 1];
    }
    arr[sizeof(arr)/sizeof(arr[0]) - 1] = 0;
  }

}


int linear_search(int key){

  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    if (arr[i] == key){
      return i;
    }
  }

  printf("%d is not found in the array.\n", key);
  return -1;
  
}



int binary_search(int key){

  int start = 0;
  int end = sizeof(arr)/sizeof(arr[0]) - 1;
  
  while (start <= end){
    int mid = start + (end - start)/2;

    if (arr[mid] == key){
      return mid;
    }
    
    else if (arr[mid] > key){
      end = mid - 1;
    }

    else{
      start = mid + 1; 

    }
  }

  printf("Not found. Make sure the array is sorted.\n");
  return -1;
}



void display_array(){
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}


int main () {

  insert_at(0, 4);
  display_array();
  insert_at(1, 5);
  display_array();
  insert_at(2, 6);
  display_array();
  insert_at(3, 7);
  insert_at(4, 10);
  display_array();
  insert_at(2, 15);
  display_array();
  insert_at(1, 3);
  display_array();
  delete_from(0);
  display_array();

  printf("Index of 4: %d\n", linear_search(4));
  printf("Index of 6: %d\n", linear_search(6));
  // printf("Index of 6 from Binary Search: %d", binary_search(6));

  return 0;
}