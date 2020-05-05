#ifndef __TEST_H
#define __TEST_H

#include <stdio.h>

typedef char *String;

void assert(int actual, int expected);
void it(String text);
void describe(String text);

void test_add_to_start(void);
void test_add_to_end(void);
void test_insert_at(void);
void test_add_unique_at_end(void);
#endif