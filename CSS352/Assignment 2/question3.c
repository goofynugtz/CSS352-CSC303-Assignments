#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 1000

/*
Roll No: 20CS8016

Q3: Write a C program that takes an input unindented C code file, 
reads its contents and write the indented code back as the same file name.
[Try using command line arguments to input the file name] 
*/

int main(int argc, char *argv[]){

  for (int file = 0; file < argc; file++){
    FILE *reader, *writer;
    reader = fopen(argv[file],"r");
    writer = fopen("indented.c","w");

    char readBuffer[BUFFER_SIZE]; char writeBuffer[BUFFER_SIZE];
    memset(readBuffer, '\0', BUFFER_SIZE);

    int indent_level = 0;

    while (fgets(readBuffer, BUFFER_SIZE, reader)){

      memset(writeBuffer, '\0', BUFFER_SIZE);   
      bool blockStart = 0;    
      for (int i = 0; i < BUFFER_SIZE; i++){    
        if (readBuffer[i] == '{'){
          indent_level++;
          blockStart = 1;
          break;
        }   
        else if (readBuffer[i] == '}'){
          indent_level--;
          break;
        }
      }   
      
      if (blockStart){
        for (int i = 0; i < indent_level - 1; i++){
          writeBuffer[i] = '\t';
        }
      } 
      else {
        for (int i = 0; i < indent_level; i++){
          writeBuffer[i] = '\t';
        }
      }
      strcat(writeBuffer, readBuffer);    
      fprintf(writer, writeBuffer);

    }   
    fclose(reader);
    fclose(writer);
  }
  
  return 0;
}