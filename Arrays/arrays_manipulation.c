#include <stdio.h>

/* 
Roll No: 20CS8016
Write a program in C to implement insertion and deletion of an element from an array.
*/

int arr[50];


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


void display_array(){
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    printf("%d ", arr[i]);
  }
  printf("\n\n");
}


int main () {

  insert_at(0, 4);
  display_array();
  insert_at(1, 5);
  display_array();
  insert_at(1, 6);
  display_array();
  insert_at(1, 7);
  display_array();
  insert_at(2, 23);
  display_array();
  insert_at(1, 32);
  display_array();
  delete_from(0);
  display_array();

  return 0;
}