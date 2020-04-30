#include "list.h"
#include <stdlib.h>

List_ptr create_list(void){
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
};

Node_ptr create_node(int value){
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
};

Status add_to_end(List_ptr list, int value){
  Node_ptr node = create_node(value);
  if(list->head == NULL){
    list->head = node;
  }
  else {
    list->last->next = node;
  }
  list->last = node;
  list->count++;
  return Success;
};