#include <stdio.h>
#include "../bin/list.h"
#include "test.h"

void runTests(void);

void runTests(void){
  test_add_to_start();
  test_add_to_end();
  test_insert_at();
}

int main() {
  printf("TESTS_______________\n");
  runTests();
  return 0;
}