//Lab: Warmup by Coles "Emi" Bergman-Corbet and Nathaniel Williams
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_INPUT 10

int countWords(char* inputs)
{
  int count = 0;
  //delimeter string for tokenization
  const char delim[] = " \t\n\v\f\r";
  char* token;
  //get first token from input
  token = strtok(inputs, delim);
  while (token != NULL)
  { //if current token exists, and is not whitespace, increment count
    if(isspace(token[0]) != 1)
    {
    count++;
    }
    //get next token
    token = strtok(NULL, delim);
  }
return count;
}

int main(int argc, char** argv) {
  char inputs[MAX_INPUT] = {'\n'};
  char last, first;
  int wordCount = 0;
  //get first set of input
  char* empty = fgets(inputs, MAX_INPUT, stdin);
  while (empty != NULL){
      //if fgets received input, call countWords
    wordCount += countWords(inputs);
    last = inputs[MAX_INPUT-2];
    //char inputs[MAX_INPUT] = {'\n'};
    empty = fgets(inputs, MAX_INPUT, stdin);
    first = inputs[0];
    /*if last char of prev input and first char of next input are both
    non-whitespace, word was cut in half and count is artificially high*/
    if (empty != NULL && isspace(last) == 0 && last != 0 &&
        isspace(first) == 0 && first != 0){
          wordCount--;
        }
  }
  printf("%d\n", wordCount);
  return 0;
}
