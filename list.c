#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
  Node_ptr new_node = create_node(value);
  Node_ptr *ptr_to_set = &list->head;
  if (list->head != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = new_node;
  list->last = new_node;
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
  list->count++;
  return Success;
};

Status check_is_num_exist(List_ptr list, int value){
  Node_ptr p_walk = list->head;
  while(p_walk != NULL){
    if(p_walk->value == value){
      return Success;
    }
    p_walk = p_walk->next;
  }
  return Failure;
}

Status add_unique(List_ptr list, int value){
  Status status = check_is_num_exist(list, value);
  if(status){
    return Failure;
  }
  return add_to_end(list, value);
}

Status remove_from_start(List_ptr list){
  if(list->count == 0){
    return Failure;
  }
  Node_ptr p_walk = list->head;
  list->head = p_walk->next;
  list->count--;
  free(p_walk);
  p_walk = NULL;
  return Success;
};

Status remove_from_end(List_ptr list){
  if(list->count <= 1){
    return remove_from_start(list);
  }
  Node_ptr p_walk = list->head;
  while(p_walk->next != NULL){
     list->last = p_walk;
    p_walk = p_walk->next;
  }
  list->last->next = NULL;
  list->count--;
  free(p_walk);
  p_walk = NULL;
  return Success;
};

Status remove_at(List_ptr list, int position)
{
  if(position < 0 || position > (list->count - 1)) {
    return Failure;
  }
  if(position == 0) {
    return remove_from_start(list);
  }
  if(position == (list->count-1)) {
    return remove_from_end(list);
  }
  int index = 1;
  Node_ptr p_walk = list->head;
  while (index != position) {
    p_walk = p_walk->next;
    index++;
  }
  Node_ptr node = p_walk->next;
  p_walk->next = node->next;
  list->count--;
  free(node);
  node = NULL;
  return Success;
}

int find_index(List_ptr list,int num) {
  int index = 0;
  const int NOT_FOUND = -1;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL ) {
    if(p_walk->value == num) {
      return index;
    }
    p_walk = p_walk->next;
    index++;
  }
  return NOT_FOUND;
};

Status remove_first_occurrence(List_ptr list, int value){
  Status status = check_is_num_exist(list, value);
  if(status == Failure) {
    return status;
  }
  int index = find_index(list, value);
  return remove_at(list, index);
}

Status remove_all_occurrences(List_ptr list, int value){
  Status status = Failure;
    while (check_is_num_exist(list, value)){
      status = remove_first_occurrence(list, value); 
    }
  return status;
}

void display(List_ptr list){
  Node_ptr p_walk = list->head;
  while (p_walk != NULL ) {
    printf("%d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}

Status clear_list(List_ptr list) {
  Node_ptr p_walk = list->head;
  Node_ptr node = NULL;

  while(p_walk != NULL) {
    node = p_walk;
    p_walk = node->next;
    free(node);
    node = NULL;
  }
  list->head = NULL;
  list->last = NULL;
  return Success;
};

void destroy_list(List_ptr list) {
  Status status = clear_list(list);
  free(list);
  list = NULL;
}