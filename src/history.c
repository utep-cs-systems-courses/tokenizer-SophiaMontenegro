#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  //List* list = (List*)malloc(sizeof(List));
  List *list;
  //list->root = NULL;
  return list;
}

void add_history(List *list, char *str){
  Item *newItem = (Item*)malloc(sizeof(Item));
  newItem->id = 0;
  newItem->str = str;
  newItem->next = NULL;

  //Checks if the list is empty
  if(list->root == NULL){
    list->root = newItem;
  }
  //Traverses through the list to get to the end
  else{
    Item *current = list->root;
    while(current != NULL){
      // current->id+=1;
      current = current->next;
    }
    //Sets new history item
    current->next = newItem;
  }
}

char* get_history(List *list, int id){
  Item* current = list-> root;
  
  while(current != NULL){
    //Checks if the current id matches with the one passed(looking for)
    if(current->id == id){
      return current-> str;
    }
    current = current->next;
  }
  return NULL;
}

void print_history(List *list){//It takes in a pointer to the linked list
  Item* current = list->root;
  //Loops through the linked list and prints out the str
  while(current != NULL){
    printf("ID: %d, String: %s\n", current->id, current->str);
    current = current->next;
  }
}

void free_history(List *list){
  Item* current = list->root;
  while(current != NULL){
    Item* next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  free(list);
}
