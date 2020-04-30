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

Status add_to_start(List_ptr list, int value){
  Node_ptr node = create_node(value);
  if(list->head != NULL){
    node->next = list->head;
  }
  else{ 
    list->last = node;
  }
  list->head = node;
  list->count++;
  return Success;
};

Status insert_at(List_ptr list, int value, int position) {
  if(position < 0 || position > list->count){
    return Failure;
  }
  if(position == 0){
    return add_to_start(list, value);
  }
  if(position == list->count){
    return add_to_end(list, value);
  }
  
  int index = 1;
  Node_ptr node = create_node(value);
  Node_ptr p_walk = list->head;
  while (index != position)
  {
    p_walk = p_walk->next;
    index++;
  }
  node->next = p_walk->next;
  p_walk->next = node;
  return Success;
};

Status add_unique(List_ptr list, int value){
  Node_ptr p_walk = list->head;
  while (p_walk != NULL ) {
    if(p_walk->value == value) {
      return Failure;
    }
    p_walk = p_walk->next;
  }
  return add_to_end(list, value);
}

