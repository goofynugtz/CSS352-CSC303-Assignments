#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Roll No: 20CS8016

Q: Write a C program to take input from a file of 2 very large numbers of order greater than 10^18 and write functions to add them up, multiply them up, and another function to get factorial of a large number say 100! or 300!. Store the result in another text file as it may be very large to manage on terminal.
*/

const char * multiplication(char A[700], char B[700]){

  char string_A[700];  
  memset(string_A, '\0', 700);

  static char result[700];
  memset(result, '\0', 700); //Resets value of static variable;

  //Starting Zero Cleanup --start
  int ind; 
  ind = -1;
  for (int i = 0; i < 700; i++) {
    if (A[i] != '0') {
      ind = i; break;
    }
  }

  for (int i = 0; i < 700 - ind; i++){
    string_A[i] = A[ind + i];
  }

  char string_B[700];
  memset(string_B, '\0', 700);

  ind = -1;
  for (int i = 0; i < 700; i++) {
    if (B[i] != '0') {
      ind = i; break;
    }
  }

  for (int i = 0; i < 700 - ind; i++){
    string_B[i] = B[ind + i];
  }
  //Starting Zero Cleanup --end

  // printf("A: %s B: %s\n", string_A, string_B);

  int i_n1 = 0;
  int i_n2 = 0;

  for (int i = strlen(string_A) - 1; i >= 0; i--){
    int carry = 0;
    int n1 = string_A[i] - '0';


    i_n2 = 0;
    
    for (int j = strlen(string_B) - 1; j >= 0; j--){
      int n2 = string_B[j] - '0';
      // printf("Previous Carry: %d\n", carry);

      int sum;
      if (result[i_n1 + i_n2]) 
        sum = n1 * n2 + (result[i_n1 + i_n2] - 48) + carry;
      else 
        sum = n1 * n2 + carry;

      carry = sum / 10;

      result[i_n1 + i_n2] = sum % 10 + 48;

      i_n2++;
    }

    if (carry > 0) 
      result[i_n1 + i_n2] += carry + 48;

    i_n1++;
  }

  //Reversing the result array
  int j = strlen(result) - 1; int i = 0; int _temp;
  while (i < j){
    _temp = result[i];
    result[i] = result[j];
    result[j] = _temp;
    i++; j--;
  }
 
  return result;
}



const char * factorial (char string[700]){

  static char buffer[700];
  memset(buffer, '\0', 700);

  char temp[700]; 
  memset(temp, '\0', 700);

  strcpy(buffer, string);

  for (int i = strlen(string) - 1; *temp != '1' || strlen(temp) != 1; i){
    // printf("Start: %s\n", buffer);

    if (string[i] == '0'){
      for (int j = i; j >= 0; j--){
        string[j] = '9';

        if (string[j-1] != '0'){
          string[j-1]--;
          strcpy(temp, multiplication(string, "1"));
          strcpy(buffer, multiplication(buffer, string));
          break;
        }
      }
    }

    if (string[i] != '0'){
      string[i]--;
    }

    strcpy(temp, multiplication(string, "1"));
    strcpy(buffer, multiplication(buffer, string));
  }

  return buffer;
}



const char * addition(char string_a[700], char string_B[700]){

  char string_A[700] = {'0'};
  strcat(string_A, string_a);

  int no_of_zeroes = abs(strlen(string_A) - strlen(string_B));
  // printf("%d\n", no_of_zeroes);

  char string_temp[700];
  for (int i = 0; i < no_of_zeroes; i++){
    string_temp[i] = '0';
  }
  string_temp[no_of_zeroes] = '\0';

  strlen(string_A) > strlen(string_B) ? strcat(string_temp, string_B) : strcat(string_temp, string_A);
  strlen(string_A) > strlen(string_B) ? sprintf(string_B, "%s" , string_temp) : sprintf(string_A, "%s" , string_temp);
  // printf("A:%s B:%s\n", string_A, string_B);

  static char result[700]; int carry = 0;

  for (int i = strlen(string_A) - 1; i != -1; i--){

    if (string_A[i] + string_B[i] + carry - 48 > 57){
      result[i] = (int)string_A[i] + (int)string_B[i] + carry - 58;
      carry = 1;  
    } else {
      result[i] = (int)string_A[i] + (int)string_B[i] + carry - 48;
      carry = 0;
    }
    // printf("%c\n", result[i]); 
  }

  result[strlen(string_A)] = '\0';

  if (result[0] == 48){
    for (int i = 0; i < strlen(result); i++){
      result[i] = result[i+1];
    }

    result[strlen(string_A) - 1] = '\0';
  };

  return result;
}



int main(){

  /*
  300! goes as long as 614 digits. So taken upper limit as 700. Highest factorial call can go upto 333!
  For Addition of more than ~300, do comment out the factorial calls on line no. 206 & 207, 
  else program might give garbage results.
  Enter the values in terminal or clear comment on line 195 for very large values in input.txt.
  */

  char string_A[700];
  char string_B[700];

  // freopen("input.txt", "r", stdin);

  // printf("Enter first number: ");
  scanf("%s", string_A);
  // printf("Enter second number: ");
  scanf("%s", string_B);

  freopen("output.txt", "w", stdout);

  printf("Sum: %s\n\n", addition(string_A, string_B));
  printf("Product: %s\n\n", multiplication(string_A, string_B));
  // printf("Factorial 1: %s\n\n", factorial(string_A));
  // printf("Factorial 2: %s\n\n", factorial(string_B));

  return 0;
}