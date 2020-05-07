#ifndef __TEST_H
#define __TEST_H

#include <stdio.h>

typedef char *String;

void assert_equal(int actual, int expected);
void assert_null(Node_ptr value);
void it(String text);
void describe(String text);

void test_create_node(void);
void test_create_list(void);
void test_add_to_start(void);
void test_add_to_end(void);
void test_insert_at(void);
void test_add_unique_at_end(void);
void test_remove_from_start(void);
void test_remove_from_end(void);
void test_remove_at(void);
void test_remove_first_occurrence(void);
void test_remove_all_occurrences(void);
void test_clear_list(void);
void test_check_is_num_exist(void);

#endif