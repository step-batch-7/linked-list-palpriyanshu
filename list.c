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

int_ptr create_int_data(int value){
  int_ptr data = malloc(sizeof(int));
  *data = value;
  return data;
}

Node_ptr create_node(Void_ptr data){
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
};

Status add_to_end(List_ptr list, Void_ptr data){
  return insert_at(list, data, list->count);
};

Status add_to_start(List_ptr list, Void_ptr data){
  return insert_at(list, data, 0);
}

Status insert_at(List_ptr list, Void_ptr data, int position) {
  if(position < 0 || position > list->count){
    return Failure;
  }
  
  Node_ptr node = create_node(data);

  if(position == list->count || list->count == 0){
    list->last = node;
  }
  if(position == 0){
    node->next = list->head;
    list->head = node;
    list->count++;
    return Success;
  }
  
  Node_ptr p_walk = list->head;
  int index = 1;
  while (index != position)
  {
    p_walk = p_walk->next;
    index++;
  }
  node->next = p_walk->next;
  p_walk->next = node;
  list->last->next = NULL;
  list->count++;
  return Success;
};

Status check_is_num_exist(List_ptr list, Void_ptr data){
  Node_ptr p_walk = list->head;
  while(p_walk != NULL){
    if(p_walk->data == data){
      return Success;
    }
    p_walk = p_walk->next;
  } 
  return Failure;
}

Status add_unique(List_ptr list, Void_ptr data){
  if(check_is_num_exist(list, data)){
    return Failure;
  }
  return insert_at(list, data, list->count);
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

int find_index(List_ptr list, Void_ptr data) {
  int index = 0;
  const int NOT_FOUND = -1;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL ) {
    if(p_walk->data == data) {
      return index;
    }
    p_walk = p_walk->next;
    index++;
  }
  return NOT_FOUND;
};

Status remove_first_occurrence(List_ptr list, Void_ptr data) {
  if(check_is_num_exist(list, data)) {
    int index = find_index(list, data);
    return remove_at(list, index);
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, Void_ptr data) {
  Status status = Failure;
    while (check_is_num_exist(list, data)){
      status = remove_first_occurrence(list, data); 
    }
  return status;
}

int is_at(List_ptr list, Void_ptr data, int position) {
  if (position > list->count - 1 || position < 0){
    return 0;
  }
  Node_ptr p_walk = list->head;
  int count = 0;
  while (count != position)
  {
    p_walk = p_walk->next;
    count++;
  }
  return p_walk->data == data;
}

void display_int(Void_ptr data){
  printf("%d ", *(int_ptr)data);
};

void display(List_ptr list, Displayer displayer){
  Node_ptr p_walk = list->head;
  while (p_walk != NULL ) {
    (*displayer)(p_walk->data);
    p_walk = p_walk->next;
  }
}

Status clear_list(List_ptr list) {
  Status status = Failure;
  while(list->head != NULL) {
    status = remove_from_start(list);
  }
  
  list->head = NULL;
  list->last = NULL;
  return status;
};

void destroy_list(List_ptr list) {
  Status status = clear_list(list);
  free(list);
  list = NULL;
}