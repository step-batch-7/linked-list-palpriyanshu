#include <stdio.h>
#include "../list.h"
#include "test.h"

void runTests(void);

void runTests(void){
  test_create_node();
  test_create_list();
  test_add_to_start();
  test_add_to_end();
  test_insert_at();
  test_add_unique_at_end();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  test_clear_list();
  test_check_is_num_exist();
}

int main() {
  printf("TESTS_START_______________\n");
  runTests();
  printf("\n\nTESTS_END_______________\n");
  return 0;
}