#ifndef __LIST_H
#define __LIST_H

typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node_ptr head;
  Node_ptr last;
  int count;
} List;

typedef List *List_ptr;

List_ptr create_list(void);
Node_ptr create_node(int value);
Status add_to_end(List_ptr, int value);
Status add_to_start(List_ptr, int value);
Status insert_at(List_ptr, int value, int position);
Status add_unique(List_ptr, int value);

void display(List_ptr);
int find_index(List_ptr list,int num);
int is_at(List_ptr list, int value, int position);

Status remove_from_start(List_ptr);
Status remove_from_end(List_ptr);
Status remove_at(List_ptr, int position);
Status remove_first_occurrence(List_ptr, int value);
Status remove_all_occurrences(List_ptr, int value);
Status clear_list(List_ptr); // Removes all elements in the list
Status check_is_num_exist(List_ptr, int value); 

void destroy_list(List_ptr); // Frees the elements and the list structure from memory

#endif