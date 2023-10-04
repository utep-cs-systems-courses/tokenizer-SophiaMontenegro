/*Building a Simple UI */
#include "tokenizer.h"
#include "history.h"
#include <stdio.h>
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
  printf("type 'QUIT' to exit");
  
  while(1){ //Infinite
   
    printf("> ");
    
    char input[100];
    //Read the input
    scanf("%s", input);

    //Check if it should exit the program
    if(isEqual(input, "QUIT")==1){
	printf("Exiting\n");
	break;
      }

    //Outputs the input
    printf(input);
  }
}
