#include <stdlib.h>
#include "test_lib.h"
#include "../list.h"
#include "tests.h"

void test_create_node(void){
  describe("# CREATE_NODE");
  int_ptr data = create_int_data(5);
  Node_ptr node = create_node(data);

  it("* should create a node with given value");
  assert_void_int_equal(node->data, data);
  assert_null(node->next);
  free(node);
};

void test_create_list(void){
  describe("# CREATE_LIST");
  it("* should create a list");
  List_ptr list = create_list();
  assert_null(list->head);
  assert_null(list->last);
  assert_int_equal(list->count, 0);

  destroy_list(list);
};

void test_add_to_start(void){
  List_ptr list = create_list();
  describe("# ADD_TO_START");
  it("* should add a number to empty list");
  int_ptr data1 = create_int_data(5);
  assert_int_equal(add_to_start(list, data1), Success);
  assert_int_equal(is_at(list, data1, 0), Success);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data1);

  it("* should add a number to the beginning of list");
  int_ptr data2 = create_int_data(5);
  assert_int_equal(add_to_start(list, data2), Success);
  assert_int_equal(is_at(list, data2, 0), Success);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data1);
  
  destroy_list(list);
};

void test_add_to_end(void){
  describe("# ADD_TO_END");
  List_ptr list = create_list();
  it("* should add a number to empty list");
  int_ptr data1 = create_int_data(6);
  assert_int_equal(add_to_end(list, data1), Success);
  assert_int_equal(is_at(list, data1, 0), Success);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data1);

  it("* should add a number to the end of list");
  int_ptr data2 = create_int_data(7);
  assert_int_equal(add_to_end(list, data2), Success);
  assert_int_equal(is_at(list, data2, 1), Success);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data2);

  destroy_list(list);
};

void test_insert_at(void){
  List_ptr list = create_list();
  describe("# INSERT_AT");
  it("* should insert at first position in empty list");
  int_ptr data1 = create_int_data(6);
  assert_int_equal(insert_at(list, data1, 0), Success);
  assert_int_equal(is_at(list, data1, 0), Success);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data1);

  it("* should insert at last position in the list");
  int_ptr data2 = create_int_data(7);
  assert_int_equal(insert_at(list, data2, 1), Success);
  assert_int_equal(is_at(list, data2, 1), 1);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data2);

  it("* should insert at first position in the list");
  int_ptr data3 = create_int_data(8);
  assert_int_equal(insert_at(list, data3, 0), Success);
  assert_int_equal(is_at(list, data3, 0), Success);
  assert_int_equal(list->count, 3);
  assert_void_int_equal(list->head->data, data3);
  assert_void_int_equal(list->last->data, data2);

  it("* should insert a number at any position in the list");
  int_ptr data4 = create_int_data(9);
  assert_int_equal(insert_at(list, data4, 1), Success);
  assert_int_equal(is_at(list, data4, 1), Success);
  assert_int_equal(list->count, 4);
  assert_void_int_equal(list->head->data, data3);
  assert_void_int_equal(list->last->data, data2);

  it("* should not insert at position which is less than list count");
  assert_int_equal(insert_at(list, data4, -1), Failure);
  assert_int_equal(list->count, 4);
  assert_void_int_equal(list->head->data, data3);
  assert_void_int_equal(list->last->data, data2);

  it("* should not insert at position which is more than list count");
  assert_int_equal(insert_at(list, data4, 6), Failure);
  assert_int_equal(list->count, 4);
  assert_void_int_equal(list->head->data, data3);
  assert_void_int_equal(list->last->data, data2);

  destroy_list(list);
};

void test_add_unique_at_end(void){
  describe("# ADD_UNIQUE_AT_END");
  List_ptr list = create_list();

  it("* should add number at first position in the empty list");
  int_ptr data1 = create_int_data(6);
  assert_int_equal(add_unique(list, data1), Success);
  assert_int_equal(is_at(list, data1, 0), Success);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data1);

  it("* should add number at last in the list if it does not exist already");
  int_ptr data2 = create_int_data(7);
  assert_int_equal(add_unique(list, data2), Success);
  assert_int_equal(is_at(list, data2, 1), Success);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data2);

  it("* should not add number in the list if it exist already");
  assert_int_equal(add_unique(list, data1), Failure);
  assert_int_equal(is_at(list, data1, 2), Failure);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data2);
  
  destroy_list(list);
};

void test_remove_from_start(){
  List_ptr list = create_list();
  describe("# REMOVE_FROM_START");
  it("* should not remove a number from empty list");
  assert_int_equal(remove_from_start(list), Failure);
  assert_int_equal(list->count, 0);

  int_ptr data1 = create_int_data(6);
  int_ptr data2 = create_int_data(7);
  add_to_start(list, data1);
  add_to_end(list, data2);

  it("* should remove a number from beginning of list");
  assert_int_equal(remove_from_start(list), Success);
  assert_int_equal(is_at(list, data1, 0), Failure);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data2);

  destroy_list(list);
}

void test_remove_from_end(){
  describe("# REMOVE_FROM_END");
  List_ptr list = create_list();
  it("* should not remove a number from empty list");
  assert_int_equal(remove_from_end(list), Failure);
  assert_int_equal(list->count, 0);

  int_ptr data1 = create_int_data(6);
  int_ptr data2 = create_int_data(7);
  add_to_start(list, data1);
  add_to_end(list, data2);

  it("* should remove a number from end of list");
  assert_int_equal(remove_from_end(list), Success);
  assert_int_equal(is_at(list, data2, 1), Failure);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data1);

  destroy_list(list);
}

void test_remove_at(){
  List_ptr list = create_list();
  describe("# REMOVE_AT");
  it("* should not remove a number from empty list");
  assert_int_equal(remove_from_start(list), Failure);
  assert_int_equal(list->count, 0);

  int_ptr data1 = create_int_data(1);
  int_ptr data2 = create_int_data(2);
  int_ptr data3 = create_int_data(3);
  int_ptr data4 = create_int_data(4);
  int_ptr data5 = create_int_data(5);

  add_to_start(list, data1);
  add_to_end(list, data2);
  add_to_end(list, data3);
  add_to_end(list, data4);
  add_to_end(list, data5);

  it("* should remove a number from a given position in the list");
  assert_int_equal(remove_at(list, 2), Success);
  assert_int_equal(is_at(list, data3, 2), Failure);
  assert_int_equal(list->count, 4);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data5);

  it("* should remove a number from beginning of list");
  assert_int_equal(remove_at(list, 0), Success);
  assert_int_equal(is_at(list, data1, 0), Failure);
  assert_int_equal(list->count, 3);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data5);

  it("* should remove a number from end of list");
  assert_int_equal(remove_at(list, 2), Success);
  assert_int_equal(is_at(list, data5, 2), Failure);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data4);

  it("* should not remove a number from list if position is less than list count");
  assert_int_equal(remove_at(list, -1), Failure);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data4);

  it("* should not remove a number from list if position is more than list count");
  assert_int_equal(remove_at(list, 3), Failure);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data4);

  destroy_list(list);
};

void test_remove_first_occurrence(){
  List_ptr list = create_list();
  describe("# REMOVE_FIRST_OCCURRENCE");
  int_ptr data1 = create_int_data(1);
  int_ptr data2 = create_int_data(2);

  it("* should not remove a number from empty list");
  assert_int_equal(remove_first_occurrence(list, data1), Failure);
  assert_int_equal(list->count, 0);

  add_to_start(list, data1);
  add_to_end(list, data2);
  add_to_end(list, data1);

  it("* should remove first occurrence of a number from start of list if it exist multiple times");
  assert_int_equal(remove_first_occurrence(list, data1), Success);
  assert_int_equal(list->count, 2);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data1);

  it("* should remove first occurrence of a number from start of list if it exist once");
  assert_int_equal(remove_first_occurrence(list, data1), Success);
  assert_int_equal(check_is_num_exist(list, data1), Failure);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data2);

  it("* should not remove a number from the list if it does not exist");
  assert_int_equal(remove_first_occurrence(list, data1), Failure);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data2);
  assert_void_int_equal(list->last->data, data2);

  destroy_list(list);
};

void test_remove_all_occurrences(){
  List_ptr list = create_list();
  describe("# REMOVE_ALL_OCCURRENCES");
  int_ptr data1 = create_int_data(1);
  int_ptr data2 = create_int_data(2);
  int_ptr data3 = create_int_data(3);

  it("* should not remove a number from empty list");
  assert_int_equal(remove_all_occurrences(list, data3), Failure);
  assert_int_equal(list->count, 0);

  add_to_start(list, data1);
  add_to_end(list, data2);
  add_to_end(list, data1);
  add_to_end(list, data3);

  it("* should remove all occurrence of a number from start of list if it exist once");
  assert_int_equal(remove_all_occurrences(list, data2), Success);
  assert_int_equal(check_is_num_exist(list, data2), Failure);
  assert_int_equal(list->count, 3);
  assert_void_int_equal(list->head->data, data1);
  assert_void_int_equal(list->last->data, data3);

  it("* should remove all occurrence of a number from start of list if it exist multiple times");
  assert_int_equal(remove_all_occurrences(list, data1), Success);
  assert_int_equal(check_is_num_exist(list, data1), Failure);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data3);
  assert_void_int_equal(list->last->data, data3);

  it("* should not remove a number from the list if it does not exist");
  assert_int_equal(remove_all_occurrences(list, data1), Failure);
  assert_int_equal(list->count, 1);
  assert_void_int_equal(list->head->data, data3);
  assert_void_int_equal(list->last->data, data3);

  destroy_list(list);
};

void test_check_is_num_exist(){
  describe("# CHECK_IS_NUM_EXIST");
  List_ptr list = create_list();
  int_ptr data1 = create_int_data(2);
  add_to_start(list, data1);
  it("* should validate if number exists in the list");
  assert_int_equal(check_is_num_exist(list, data1), Success);

  it("* should inValidate if number does not exists in the list");
  int_ptr data2 = create_int_data(3);
  assert_int_equal(check_is_num_exist(list, data2), Failure);

  destroy_list(list);
};

void test_clear_list(){
 describe("# CLEAR_LIST");
 List_ptr list = create_list();
 it("* should not clear empty list");
 assert_int_equal(clear_list(list), Failure);
 assert_int_equal(list->count, 0);

 int_ptr data = create_int_data(6);
 add_to_start(list, data);

 it("* should clear the list if exist and make count 0");
 assert_int_equal(clear_list(list), Success);
 assert_int_equal(check_is_num_exist(list, data), Failure);
 assert_int_equal(list->count, 0);
  
 destroy_list(list);
};
