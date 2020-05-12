#ifndef __LIST_H
#define __LIST_H

typedef void *Void_ptr;
typedef int *int_ptr;

typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  Void_ptr data;
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
typedef void (*Displayer)(Void_ptr data);

int_ptr create_int_data(int value);
List_ptr create_list(void);
Node_ptr create_node(Void_ptr data);
Status add_to_end(List_ptr, Void_ptr data);
Status add_to_start(List_ptr, Void_ptr data);
Status insert_at(List_ptr, Void_ptr data, int position);
Status add_unique(List_ptr, Void_ptr data);

void display_int(Void_ptr data); // Frees the elements and the list structure from memory
void display(List_ptr list, Displayer displayer);
int find_index(List_ptr list,Void_ptr data);
int is_at(List_ptr list, Void_ptr data, int position);

Status remove_from_start(List_ptr);
Status remove_from_end(List_ptr);
Status remove_at(List_ptr, int position);
Status remove_first_occurrence(List_ptr, Void_ptr data);
Status remove_all_occurrences(List_ptr, Void_ptr data);
Status clear_list(List_ptr); // Removes all elements in the list
Status check_is_num_exist(List_ptr, Void_ptr data); 

void destroy_list(List_ptr); // Frees the elements and the list structure from memory

#endif