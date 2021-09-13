#include <stdio.h>
#include <stdbool.h>
#include <windef.h>
#define MAXSIZE 100

/* 
Roll No: 20CS8016
*/

int arr[MAXSIZE];
int size;


void insert_at(int index, int value){

  if(index >= MAXSIZE || index < 0){
    printf("Array overflow!\n");
    return;
  }

  if(!arr[index]){
    arr[index] = value;
    size = max(index, size) + 1;
  } else {

    for (int i = MAXSIZE - 1; i > index; i--){
      arr[i] = arr[i - 1];
    }

    arr[index] = value;
    size = max(index, size) + 1;
  }
}


void delete_from(int index){

  if(index < 0 || index >= size){
    printf("Invalid index. Index not in range.\nEnter in range (0 : %d)\n", size-1);
    return;
  }

  if(!arr[index]){
    printf("Index %d is already empty\n", index);
  } else {

    int deleted_value = arr[index];

    for (int i = index; i < size; i++){
      arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0;
    size--;
    printf("%d at index %d has been deleted\n", deleted_value, index);
  }
}


int search(int key){

  for (int i = 0; i < size; i++){
    if (arr[i] == key){
      return i;
    }
  }

  printf("%d is not found in the array.\n", key);
  return -1;
}


void display_array(){

  for (int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n---\n");
}


int main () {

  //Original Array
  printf("Enter no. of elements: "); 
  scanf("%d", &size);

  printf("Enter the array below:\n");
  for (int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }

  //Driver Code
  bool want_to_exit = 0;
  while (!want_to_exit){
    int userchoice;
    printf("\n1: Insert new element\n2: Delete an index\n3: Search for a value\n0: Quit\n");
    printf("Choose option: ");
    scanf("%d", &userchoice);

    int index, value, key;

    switch (userchoice) {
      case 1:
        printf("\nEnter #index #value: ");
        scanf("%d %d", &index, &value);
        insert_at(index, value);
        printf("Array: "); display_array();
        break;
      
      case 2:
        printf("\nEnter #index to be deleted: ");
        scanf("%d", &index);
        delete_from(index);
        printf("Array: "); display_array();
        break;

      case 3:
        printf("\nEnter #value to search: ");
        scanf("%d", &key);
        int position = search(key);
        printf("%d is at position %d\n", key, position);
        break;

      default:
        want_to_exit = 1;
        break;
    }
  }

  return 0;
}
