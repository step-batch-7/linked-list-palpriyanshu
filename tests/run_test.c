#include <stdio.h>
#include "../list.h"
#include "test.h"

void runTests(void);

void runTests(void){
  test_add_to_start();
  test_add_to_end();
  test_insert_at();
  test_add_unique_at_end();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
}

int main() {
  printf("TESTS_______________\n");
  runTests();
  return 0;
}