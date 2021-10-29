#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
Roll No: 20CS8016

Q4: Write a C program to perform matrix multiplication. 
Use dynamic allocation 2-D arrays to store the matrices. 
[Use malloc and free and make sure you explicitly clear the garbage after processing.]
*/

int **arr1;
int rows1, columns1;
int **arr2;
int rows2, columns2;


int ** multiply(int ** arr1, int ** arr2) {

  int ** result;
  result = (int **) malloc (sizeof(int *) * rows2);
  for (int i = 0; i < rows2; i++){
    result[i] = (int *) malloc (sizeof(int) * columns1);
  }

  //Result Matrix is of Order r1 * c2;
  for (int i = 0; i < rows1; i++)
    for (int j = 0; j < columns2; j++)
      result[i][j] = 0;

  for (int i = 0; i < rows1; i++){
    for (int j = 0; j < columns2; j++){
      for (int k = 0; k < columns1; k++){
        result[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }

  return result;
}


int ** values_in (int ** arr, int rows, int columns){

  printf("Enter the values: ");

  arr = (int **) malloc (sizeof(int *) * rows);
  for (int i = 0; i < rows; i++){
    arr[i] = (int *) malloc (sizeof(int) * columns);
  }

  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  return arr;
}


void display_matrix(int ** matrix, int rows, int columns) {

  printf("\n");

  for (int i = 0; i < rows; i++){
    printf("|");
    for (int j = 0; j < columns; j++){
      printf(" %d ", matrix[i][j]);
    }
    printf("|\n");
  }

  printf("\n");
}


void deallocate_memory(int ** result){
  
  for (int i = 0; i < rows1; i++)
    free(arr1[i]);
  free(arr1);
  for (int i = 0; i < rows2; i++)
    free(arr2[i]);
  free(arr2);
  for (int i = 0; i < rows1; i++)
    free(result[i]);
  free(result);

  return;
}


int main () {

  printf("\nEnter order of first matrix: ");
  scanf("%d %d", &rows1, &columns1);
  arr1 = values_in(arr1, rows1, columns1);

  printf("First Matrix is: \n");
  display_matrix(arr1, rows1, columns1);

  printf("Enter order of second matrix: ");
  scanf("%d %d", &rows2, &columns2);
  

  if (rows2 != columns1) {
    printf("Second Matrix Rows should be == First matrix's column: %d.\n", columns1);
    printf("Exiting Program...\n");
    return 0;
  } else {
    arr2 = values_in(arr2, rows2, columns2);
  }
  printf("Second Matrix is: \n");
  display_matrix(arr2, rows2, columns2);

  int ** result = multiply(arr1, arr2);
  printf("Result:\n");
  display_matrix(result, rows1, columns2);

  deallocate_memory(result);

  return 0;
}