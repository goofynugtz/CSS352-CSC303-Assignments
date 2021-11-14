#include <stdio.h>
#include <stdlib.h>
#include <windef.h>
#define departmentName database[i].name_of_dept
#define totalStudents database[i].cgpa[0]
#define grade database[i].cgpa
#define highestCGPA database[i].highest_gpa
#define highScorers database[i].highest_scorers
#define N 2


/*
Roll No: 20CS8016

Q6: Write a C program to store the CGPA obtained by students of different dept. 
Note that Institute is having a fixed number of Departments
(i.e. the number of Depts are known prior to execution) 
but the number of students in each Dept is known in runtime. 
Moreover different Dept. have different student capacity. 
Compute the highest CGPA obtained in each Dept. and highest CGPA among all Dept. 

Hint: Using dynamic allocation, use malloc and free. 
Make sure you explicitly clear the garbage after processing is done.
*/


typedef struct department {
  char name_of_dept[5];
  float * cgpa;
  float highest_gpa;
  int * highest_scorers;
} department;


department database[N];


void displayDatabase() {
  for (int i = 0; i < N; i++){
    printf("\n%s: \n\n", departmentName);
    printf("RollNo.  CGPA\n");
    for (int roll = 1; roll <= totalStudents; roll++){
      printf("     %d. %.3f\n", roll, grade[roll]);
    }
    printf("Highest CGPA: %.3f, RollNo(s): ", highestCGPA);
    for (int index = 1; index <= highScorers[0]; index++){
      printf("%d ", highScorers[index]);
    }
    printf("\n\n============\n");
  }
}


void fillHighestGPA(){
  for (int i = 0; i < N; i++){

    for (int roll = 1; roll <= totalStudents; roll++){
      highestCGPA = max(highestCGPA, grade[roll]);
    }

    int no_of_student = 0;
    for (int roll = 1; roll <= totalStudents; roll++){
      if (grade[roll] == highestCGPA){
        no_of_student++;
      }
    }

    highScorers = (int *) malloc (sizeof(int) * (no_of_student + 1));
    highScorers[0] = no_of_student;

    for (int roll = 1, index = 1; roll <= totalStudents; roll++){
      if (grade[roll] == highestCGPA){
        highScorers[index] = roll;
        index++;
      } else {
        continue;
      }
    }
  }
}


void deallocateMemory() {

  for (int i = 0; i < N; i++){
    free(grade);
    free(highScorers);
  }
}


int main(){

  for (int i = 0; i < N; i++){
    printf("Department Name: ");
    scanf("%s", departmentName);

    printf("Number of Students: ");
    int size; scanf("%d", &size);

    grade = (float *)malloc (sizeof(float) * (size + 1));
    totalStudents = size;

    printf("Enter Grades below\n");
    for (int roll = 1; roll <= size; roll++){
      printf("     %d. ", roll);
      scanf("%f", &grade[roll]);
    }
  }

  fillHighestGPA();

  freopen("output.txt", "w", stdout);
  displayDatabase();
  deallocateMemory();

  return 0;
}