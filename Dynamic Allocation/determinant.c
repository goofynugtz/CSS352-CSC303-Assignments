#include <stdio.h>
#include <stdlib.h>

static int **arr;
int side;

int calculate_determinant(int ** arr, int side) {

  int determinant;
  int power = 1;
  if (side == 1){
    return (arr[0][0]);
  } else {
    determinant = 0;
    int ** minor; int size = side - 1;
    for (int axis = 0; axis < side; axis++){
      int row = 0, column = 0;

      minor = (int **) malloc (sizeof(int *) * (size));
      for (int i = 0; i < size; i++){
        minor[i] = (int *) malloc (sizeof(int) * (size));
      }

      for (int i = 0; i < side; i++){
        for (int j = 0; j < side; j++){
          if (i != 0 && j != axis){
            minor[row][column] = arr[i][j];

            if (column < side - 2){
              column++;
            } else {
              column = 0;
              row++;
            }
          }
        }
      }

      determinant += power * (arr[0][axis] * calculate_determinant(minor, size));
      power *= (-1);
    }
  }

  return determinant;
}


void insert_values_of_matrix (){

  printf("Enter the values below: \n");

  arr = (int **) malloc (sizeof(int *) * side);
  for (int i = 0; i < side; i++){
    arr[i] = (int *) malloc (sizeof(int) * side);
  }

  //Input
  for (int i = 0; i < side; i++){
    for (int j = 0; j < side; j++){
      scanf("%d", &arr[i][j]);
    }
  }
}


void display_matrix(int **matrix) {

  printf("\n");

  for (int i = 0; i < side; i++){
    for (int j = 0; j < side; j++){

      if (j == 0){
        printf("| %d ", matrix[i][j]);
      } else if (j == side - 1){
        printf(" %d |", matrix[i][j]);
      } else {
        printf(" %d ", matrix[i][j]);
      }
    }
    printf("\n");
  }

  printf("\n");
}


int main () {

  printf("Enter order of matrix: ");
  scanf("%d", &side);

  insert_values_of_matrix();
  // display_matrix(arr);

  int determinant = calculate_determinant(arr, side);
  printf("Determinant: %d\n", determinant);

  return 0;
}