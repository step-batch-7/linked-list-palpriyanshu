#ifndef __TEST_H
#define __TEST_H

#include <stdio.h>

typedef char *String;

void assert(int status);
void it(String text);
void describe(String text);

void test_add_to_start(void);
void test_add_to_end(void);
#endif