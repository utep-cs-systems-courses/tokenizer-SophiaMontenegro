/*Building a Simple UI */
#include "tokenizer.h"
#include "history.h"
#include <stdio.h>

//The following method checks if two strings are equal
int isEqual(const char *str1, const char *str2){
  while(*str1 != '\0' && *str2 != '\0'){
    if (*str1 != *str2)
      return 0;
    str1++;
    str2++;
  }
  return (*str1 == '\0' && *str2 == '\0');
}
int main(){
  
  printf("type 'QUIT' to exit\n");
  while(1){
    printf("> ");
    char input[100];

    //scan
    scanf("%s", input);

    if(isEqual(input, "QUIT") == 1){
      printf("Goodbyeeeeeeeeee");
      break;
    }
    printf(input);    
  }






}







  
/*
int main(){
  //Directions:
  printf("type 'QUIT' to exit, 'PRINTTOKEN' to print token vector, and 'PRINTHISTORY' to print history");
  
  List *historyList = init_history();
  char input[100];

  while(1){ //Infinite
   
    printf("> ");
    
    //Read the input
    scanf("%s", input);
    //Check if it should exit the program
    if(isEqual(input, "QUIT")==1){
	printf("Exiting\n");
	free_history(historyList);
	break;
    }
    else if (input[0] == '!'){
      int id = input[1] - 48;
      char *str = get_history(historyList, id);
      if(str){
	char **returnToken = tokenize(input);
	print_tokens(returnToken);
	free_tokens(returnToken);
      }
      else{
	printf("There is no such history item");
      }
    }
    else{
      add_history(historyList, input);
      char **returnToken = tokenize(input);
      print_tokens(returnToken);
      free_tokens(returnToken);
      //Outputs the input
      // printf(input);
    }
    print_history(historyList);
  }
}*/
