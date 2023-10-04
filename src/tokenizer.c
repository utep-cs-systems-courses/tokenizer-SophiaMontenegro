#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  return (c == ' ' || c == '\t');
}

int non_space_char(char c){
  return (c != ' ' && c != '\t');
}

char *token_start(char *str){
  //Should skip the whitespace chars
  while (*str != '\0' && space_char(*str)){
    str++;
  }
  
  //Checks if the str is empty or has only whitespaces
  if(*str == '\0'){
    return NULL;
  }
  
  //End of the token
  char *end = str;
  while(*end != '\0' && !(space_char(*end))){
      end++;
  }
    
  //Return the pointer of the first character  
  return str;
}
  
char *token_terminator(char *token){
  
  //It iterates through the chars of the tokem until it reaches the null terminator
  while(*token != '\0'){
    token++;
  }

  //Returns the pointer to the terminator char
  return token;
}

int count_tokens(char *str){
  int count = 0;

  int prev_space = 1;

  while(*str != '\0'){
    int curr_space = space_char(*str);

    //Increment the count if the curr char is not a space char and the prev char is
    if(!curr_space &&  prev_space){
      count++;
    }

    prev_space = curr_space;
    str++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *newStr = (char*)malloc((len + 1) * sizeof(char));

  //Copy char fron  inStr to newStr
  for(int i = 0; i < len; i++){
    newStr[i] = inStr[i];
  }

  //Add the terminator to newStr
  newStr[len] = '\0';
  return newStr;
}

char **tokenize(char* str){
  int numTokens = count_tokens(str);

  //Allocate memory for the vector of tokens
  char **tokens = (char**)malloc((numTokens + 1) * sizeof(char*));

  int tokenIndex = 0;
  int prev_space = 1;

  while(*str != '\0'){
    int curr_space = space_char(*str);

    //When the curr_space is not a space char and then the prev_space is a space char
    //then there is a new token
    if(!curr_space && prev_space){

      int tokenLen = 0;
      char *tokenStart = str;

      while(!space_char(*str) && *str != '\0'){
	tokenLen++;
	str++;
      }
      
      //Allocate memory for the token
      char* token = (char*)malloc((tokenLen + 1) * sizeof(char));

      //Copy the chars from the str
      for(int i = 0; i < tokenLen; i++){
	token[i] = tokenStart[i];
      }

      token[tokenLen] = '\0';

      //Add the token to the vector
      tokens[tokenIndex] = token;
      tokenIndex++;
    }

    prev_space = curr_space;
    str++;
  }
  tokens[numTokens] = 0;
  return tokens;
}

void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != 0){
    printf("%s\n", tokens[i]);//tokens is a pointer to a pointer not an array
    i++;
  }
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != 0){//check to see if this will work
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
