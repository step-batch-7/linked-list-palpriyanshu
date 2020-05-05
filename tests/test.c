#include <stdio.h>
#include "list.h"
#include "test.h"

void assert(status){
  printf("%s\n", status ? "✅" : "❌");
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
  assert(add_to_start(list, 6));
  it("* should add a number to the beginning of list");
  assert(add_to_start(list, 7));
  destroy_list(list);
};

void test_add_to_end(void){
  List_ptr list = create_list();
  describe("# ADD_TO_END");
  it("* should add a number to empty list");
  assert(add_to_start(list, 6));
  it("* should add a number to the end of list");
  assert(add_to_start(list, 7));
  destroy_list(list);
};