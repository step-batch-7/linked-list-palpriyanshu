#include <stdlib.h>
#include "test_lib.h"
#include "../list.h"
#include "tests.h"

void test_create_node(void){
  describe("# CREATE_NODE");
  Node_ptr node = create_node(1);

  it("* should create a node with given value");
  assert_equal(node->value, 1);
  assert_null(node->next);
  free(node);
};

void test_create_list(void){
  describe("# CREATE_LIST");
  it("* should create a list");
  List_ptr list = create_list();
  assert_null(list->head);
  assert_null(list->last);
  assert_equal(list->count, 0);

  destroy_list(list);
};

void test_add_to_start(void){
  List_ptr list = create_list();
  describe("# ADD_TO_START");
  it("* should add a number to empty list");
  assert_equal(add_to_start(list, 6), Success);
  assert_equal(is_at(list, 6, 0), Success);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 6);

  it("* should add a number to the beginning of list");
  assert_equal(add_to_start(list, 7), Success);
  assert_equal(is_at(list, 7, 0), Success);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 7);
  assert_equal(list->last->value, 6);
  
  destroy_list(list);
};

void test_add_to_end(void){
  List_ptr list = create_list();
  describe("# ADD_TO_END");
  it("* should add a number to empty list");
  assert_equal(add_to_end(list, 6), Success);
  assert_equal(is_at(list, 6, 0), Success);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 6);

  it("* should add a number to the end of list");
  assert_equal(add_to_end(list, 7), Success);
  assert_equal(is_at(list, 7, 1), Success);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 7);

  destroy_list(list);
};

void test_insert_at(void){
  List_ptr list = create_list();
  describe("# INSERT_AT");
  it("* should insert at first position in empty list");
  assert_equal(insert_at(list, 6, 0), Success);
  assert_equal(is_at(list, 6, 0), Success);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 6);

  it("* should insert at last position in the list");
  assert_equal(insert_at(list, 7, 1), Success);
  assert_equal(is_at(list, 7, 1), 1);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 7);

  it("* should insert at first position in the list");
  assert_equal(insert_at(list, 8, 0), Success);
  assert_equal(is_at(list, 8, 0), Success);
  assert_equal(list->count, 3);
  assert_equal(list->head->value, 8);
  assert_equal(list->last->value, 7);

  it("* should insert a number at any position in the list");
  assert_equal(insert_at(list, 9, 1), Success);
  assert_equal(is_at(list, 9, 1), Success);
  assert_equal(list->count, 4);
  assert_equal(list->head->value, 8);
  assert_equal(list->last->value, 7);

  it("* should not insert at position which is less than list count");
  assert_equal(insert_at(list, 9, -1), Failure);
  assert_equal(list->count, 4);
  assert_equal(list->head->value, 8);
  assert_equal(list->last->value, 7);

  it("* should not insert at position which is more than list count");
  assert_equal(insert_at(list, 9, 6), Failure);
  assert_equal(list->count, 4);
  assert_equal(list->head->value, 8);
  assert_equal(list->last->value, 7);

  destroy_list(list);
};

void test_add_unique_at_end(void){
  List_ptr list = create_list();
  describe("# ADD_UNIQUE_AT_END");
  it("* should add number at first position in the empty list");
  assert_equal(add_unique(list, 6), Success);
  assert_equal(is_at(list, 6, 0), Success);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 6);

  it("* should add number at last in the list if it does not exist already");
  assert_equal(add_unique(list, 7), Success);
  assert_equal(is_at(list, 7, 1), Success);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 7);

  it("* should not add number in the list if it exist already");
  assert_equal(add_unique(list, 6), Failure);
  assert_equal(is_at(list, 6, 2), Failure);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 7);
  
  destroy_list(list);
};

void test_remove_from_start(){
  List_ptr list = create_list();
  describe("# REMOVE_FROM_START");
  it("* should not remove a number from empty list");
  assert_equal(remove_from_start(list), Failure);
  assert_equal(list->count, 0);

  add_to_start(list, 6);
  add_to_end(list, 7);

  it("* should remove a number from beginning of list");
  assert_equal(remove_from_start(list), Success);
  assert_equal(is_at(list, 6, 0), Failure);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 7);
  assert_equal(list->last->value, 7);

  destroy_list(list);
}

void test_remove_from_end(){
  List_ptr list = create_list();
  describe("# REMOVE_FROM_END");
  it("* should not remove a number from empty list");
  assert_equal(remove_from_end(list), Failure);
  assert_equal(list->count, 0);

  add_to_start(list, 6);
  add_to_end(list, 7);

  it("* should remove a number from end of list");
  assert_equal(remove_from_end(list), Success);
  assert_equal(is_at(list, 7, 1), Failure);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 6);
  assert_equal(list->last->value, 6);

  destroy_list(list);
}

void test_remove_at(){
  List_ptr list = create_list();
  describe("# REMOVE_AT");
  it("* should not remove a number from empty list");
  assert_equal(remove_from_start(list), Failure);
  assert_equal(list->count, 0);

  add_to_start(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);

  it("* should remove a number from a given position in the list");
  assert_equal(remove_at(list, 2), Success);
  assert_equal(is_at(list, 3, 2), Failure);
  assert_equal(list->count, 4);
  assert_equal(list->head->value, 1);
  assert_equal(list->last->value, 5);

  it("* should remove a number from beginning of list");
  assert_equal(remove_at(list, 0), Success);
  assert_equal(is_at(list, 1, 0), Failure);
  assert_equal(list->count, 3);
  assert_equal(list->head->value, 2);
  assert_equal(list->last->value, 5);

  it("* should remove a number from end of list");
  assert_equal(remove_at(list, 2), Success);
  assert_equal(is_at(list, 5, 2), Failure);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 2);
  assert_equal(list->last->value, 4);

  it("* should not remove a number from list if position is less than list count");
  assert_equal(remove_at(list, -1), Failure);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 2);
  assert_equal(list->last->value, 4);

  it("* should not remove a number from list if position is more than list count");
  assert_equal(remove_at(list, 3), Failure);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 2);
  assert_equal(list->last->value, 4);

  destroy_list(list);
};

void test_remove_first_occurrence(){
  List_ptr list = create_list();
  describe("# REMOVE_FIRST_OCCURRENCE");
  it("* should not remove a number from empty list");
  assert_equal(remove_first_occurrence(list, 3), Failure);
  assert_equal(list->count, 0);

  add_to_start(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 1);

  it("* should remove first occurrence of a number from start of list if it exist multiple times");
  assert_equal(remove_first_occurrence(list, 1), Success);
  assert_equal(list->count, 2);
  assert_equal(list->head->value, 2);
  assert_equal(list->last->value, 1);

  it("* should remove first occurrence of a number from start of list if it exist once");
  assert_equal(remove_first_occurrence(list, 1), Success);
  assert_equal(check_is_num_exist(list, 1), Failure);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 2);
  assert_equal(list->last->value, 2);

  it("* should not remove a number from the list if it does not exist");
  assert_equal(remove_first_occurrence(list, 3), Failure);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 2);
  assert_equal(list->last->value, 2);

  destroy_list(list);
};

void test_remove_all_occurrences(){
  List_ptr list = create_list();
  describe("# REMOVE_ALL_OCCURRENCES");
  it("* should not remove a number from empty list");
  assert_equal(remove_all_occurrences(list, 3), Failure);
  assert_equal(list->count, 0);

  add_to_start(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 1);
  add_to_end(list, 3);

  it("* should remove all occurrence of a number from start of list if it exist once");
  assert_equal(remove_all_occurrences(list, 2), Success);
  assert_equal(check_is_num_exist(list, 2), Failure);
  assert_equal(list->count, 3);
  assert_equal(list->head->value, 1);
  assert_equal(list->last->value, 3);

  it("* should remove all occurrence of a number from start of list if it exist multiple times");
  assert_equal(remove_all_occurrences(list, 1), Success);
  assert_equal(check_is_num_exist(list, 1), Failure);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 3);
  assert_equal(list->last->value, 3);

  it("* should not remove a number from the list if it does not exist");
  assert_equal(remove_all_occurrences(list, 4), Failure);
  assert_equal(list->count, 1);
  assert_equal(list->head->value, 3);
  assert_equal(list->last->value, 3);

  destroy_list(list);
};

void test_check_is_num_exist(){
  List_ptr list = create_list();
  describe("# CHECK_IS_NUM_EXIST");

  add_to_start(list, 2);
  it("* should validate if number exists in the list");
  assert_equal(check_is_num_exist(list, 2), Success);

  it("* should inValidate if number does not exists in the list");
  assert_equal(check_is_num_exist(list, 3), Failure);

  destroy_list(list);
};

void test_clear_list(){
 describe("# CLEAR_LIST");
 List_ptr list = create_list();
 it("* should not clear empty list");
 assert_equal(clear_list(list), Failure);
 assert_equal(list->count, 0);

 add_to_start(list, 2);

 it("* should clear the list if exist and make count 0");
 assert_equal(clear_list(list), Success);
 assert_equal(check_is_num_exist(list, 2), Failure);
 assert_equal(list->count, 0);
  
 destroy_list(list);
};

void test_destroy_list(){
  describe("# DESTROY_LIST");
  List_ptr list = create_list();

  it("* should destroy list");
  assert_null(list);
  destroy_list(list);
};