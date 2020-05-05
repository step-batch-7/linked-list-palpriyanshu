#include <stdio.h>
#include "../list.h"
#include "test.h"

void assert(actual, expected){
  printf("%s", actual == expected ? " ✅" : " ❌");
};

void it(String text){
  printf("\n  %s :",text);
}

void describe(String text){
  printf("\n\n%s",text);
}

void test_add_to_start(void){
  List_ptr list = create_list();
  describe("# ADD_TO_START");
  it("* should add a number to empty list");
  assert(add_to_start(list, 6), Success);
  assert(list->count, 1);
  assert(list->head->value, 6);
  assert(list->last->value, 6);

  it("* should add a number to the beginning of list");
  assert(add_to_start(list, 7), Success);
  assert(list->count, 2);
  assert(list->head->value, 7);
  assert(list->last->value, 6);
  
  destroy_list(list);
};

void test_add_to_end(void){
  List_ptr list = create_list();
  describe("# ADD_TO_END");
  it("* should add a number to empty list");
  assert(add_to_end(list, 6), Success);
  assert(list->count, 1);
  assert(list->head->value, 6);
  assert(list->last->value, 6);

  it("* should add a number to the end of list");
  assert(add_to_end(list, 7), Success);
  assert(list->count, 2);
  assert(list->head->value, 6);
  assert(list->last->value, 7);

  destroy_list(list);
};

void test_insert_at(void){
  List_ptr list = create_list();
  describe("# INSERT_AT");
  it("* should insert at first position in empty list");
  assert(insert_at(list, 6, 0), Success);
  assert(list->count, 1);
  assert(list->head->value, 6);
  assert(list->last->value, 6);

  it("* should insert at last position in the list");
  assert(insert_at(list, 7, 1), Success);
  assert(list->count, 2);
  assert(list->head->value, 6);
  assert(list->last->value, 7);

  it("* should insert at first position in the list");
  assert(insert_at(list, 8, 0), Success);
  assert(list->count, 3);
  assert(list->head->value, 8);
  assert(list->last->value, 7);

  it("* should insert a number at any position in the list");
  assert(insert_at(list, 9, 1), Success);
  assert(list->count, 4);
  assert(list->head->value, 8);
  assert(list->last->value, 7);

  it("* should not insert at position which is less than list count");
  assert(insert_at(list, 9, -1), Failure);
  assert(list->count, 4);
  assert(list->head->value, 8);
  assert(list->last->value, 7);

  it("* should not insert at position which is more than list count");
  assert(insert_at(list, 9, 6), Failure);
  assert(list->count, 4);
  assert(list->head->value, 8);
  assert(list->last->value, 7);

  destroy_list(list);
};

void test_add_unique_at_end(void){
  List_ptr list = create_list();
  describe("# ADD_UNIQUE_AT_END");
  it("* should add number at first position in the empty list");
  assert(add_unique(list, 6), Success);
  assert(list->count, 1);
  assert(list->head->value, 6);
  assert(list->last->value, 6);

  it("* should add number at last in the list if it is not exist already");
  assert(add_unique(list, 7), Success);
  assert(list->count, 2);
  assert(list->head->value, 6);
  assert(list->last->value, 7);

  it("* should not add number in the list if it exist already");
  assert(add_unique(list, 7), Failure);
  assert(list->count, 2);
  assert(list->head->value, 6);
  assert(list->last->value, 7);
  
  destroy_list(list);
};

void test_remove_from_start(){
  List_ptr list = create_list();
  describe("# REMOVE_FROM_START");
  it("* should not remove a number from empty list");
  assert(remove_from_start(list), Failure);
  assert(list->count, 0);

  add_to_start(list, 6);
  add_to_end(list, 7);

  it("* should remove a number from beginning of list");
  assert(remove_from_start(list), Success);
  assert(list->count, 1);
  assert(list->head->value, 7);
  assert(list->last->value, 7);

  destroy_list(list);
}

void test_remove_from_end(){
  List_ptr list = create_list();
  describe("# REMOVE_FROM_END");
  it("* should not remove a number from empty list");
  assert(remove_from_start(list), Failure);
  assert(list->count, 0);

  add_to_start(list, 6);
  add_to_end(list, 7);

  it("* should remove a number from end of list");
  assert(remove_from_end(list), Success);
  assert(list->count, 1);
  assert(list->head->value, 6);
  assert(list->last->value, 6);

  destroy_list(list);
}

void test_remove_at(){
  List_ptr list = create_list();
  describe("# REMOVE_AT");
  it("* should not remove a number from empty list");
  assert(remove_from_start(list), Failure);
  assert(list->count, 0);

  add_to_start(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);

  it("* should remove a number from a given position in the list");
  assert(remove_at(list, 2), Success);
  assert(list->count, 4);
  assert(list->head->value, 1);
  assert(list->last->value, 5);

  it("* should remove a number from beginning of list");
  assert(remove_at(list, 0), Success);
  assert(list->count, 3);
  assert(list->head->value, 2);
  assert(list->last->value, 5);

  it("* should remove a number from end of list");
  assert(remove_at(list, 2), Success);
  assert(list->count, 2);
  assert(list->head->value, 2);
  assert(list->last->value, 4);

  it("* should not remove a number from list if position is less than list count");
  assert(remove_at(list, -1), Failure);
  assert(list->count, 2);
  assert(list->head->value, 2);
  assert(list->last->value, 4);

  it("* should not remove a number from list if position is more than list count");
  assert(remove_at(list, 3), Failure);
  assert(list->count, 2);
  assert(list->head->value, 2);
  assert(list->last->value, 4);

  destroy_list(list);
};

void test_remove_first_occurrence(){
  List_ptr list = create_list();
  describe("# REMOVE_FIRST_OCCURRENCE");
  it("* should not remove a number from empty list");
  assert(remove_first_occurrence(list, 3), Failure);
  assert(list->count, 0);

  add_to_start(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 1);

  it("* should remove first occurrence of a number from start of list if it exist multiple times");
  assert(remove_first_occurrence(list, 1), Success);
  assert(list->count, 2);
  assert(list->head->value, 2);
  assert(list->last->value, 1);

  it("* should remove first occurrence of a number from start of list if it exist once");
  assert(remove_first_occurrence(list, 1), Success);
  assert(list->count, 1);
  assert(list->head->value, 2);
  assert(list->last->value, 2);


  it("* should not remove a number from the list if it is not exist");
  assert(remove_first_occurrence(list, 3), Failure);
  assert(list->count, 1);
  assert(list->head->value, 2);
  assert(list->last->value, 2);

  destroy_list(list);
};
