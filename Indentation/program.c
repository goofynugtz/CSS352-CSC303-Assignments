#include <stdio.h>
int main(){
printf("Start Line");
if ("1" == 1){
printf("True");
printf("True Again");
if (1){
printf("Inside check Statement");
}
else
printf("Inside checks but in else");
}
for (int i = 0; i < 20; i++){
for (int j = i; j < 15; j++){
for (int k = i + j; k < 100; k++){
int something = 0;
something++;
printf("Inside Nested Loop Line 1");
printf("Inside Nested Loop Line 1");
printf("Inside Nested Loop Line 1");
printf("Inside Nested Loop Line 1");
}
}
}
printf("Hello World");
printf("End Line");
return 0;
}