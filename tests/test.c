#include <stdio.h>
#include "../bin/list.h"
#include "test.h"

void assert(actual, expected){
  printf("%s\n", actual == expected ? "✅" : "❌");
};

void it(String text){
  printf("  %s : ",text);
}

void describe(String text){
  printf("%s\n",text);
}

void test_add_to_start(void){
  List_ptr list = create_list();
  describe("# ADD_TO_START");
  it("* should add a number to empty list");
  assert(add_to_start(list, 6), Success);
  it("* should add a number to the beginning of list");
  assert(add_to_start(list, 7), Success);
  destroy_list(list);
};

void test_add_to_end(void){
  List_ptr list = create_list();
  describe("# ADD_TO_END");
  it("* should add a number to empty list");
  assert(add_to_start(list, 6), Success);
  it("* should add a number to the end of list");
  assert(add_to_start(list, 7), Success);
  destroy_list(list);
};

void test_insert_at(void){
  List_ptr list = create_list();
  describe("# INSERT_AT");
  it("* should insert at first position in empty list");
  assert(insert_at(list, 6, 0), Success);
  it("* should insert at last position in the list");
  assert(insert_at(list, 7, 1), Success);
  it("* should insert at first position in the list");
  assert(insert_at(list, 8, 0), Success);
  it("* should insert a number at any position in the list");
  assert(insert_at(list, 9, 1), Success);
  it("* should not insert at position which is less than list count");
  assert(insert_at(list, 9, -1), Failure);
  it("* should not insert at position which is more than list count");
  assert(insert_at(list, 9, 6), Failure);
  destroy_list(list);
};