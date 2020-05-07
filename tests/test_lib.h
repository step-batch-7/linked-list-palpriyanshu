#ifndef __TEST_LIB_H
#define __TEST_LIB_H

typedef char *String;
typedef void *Void_ptr;

void assert_equal(int actual, int expected);
void assert_null(Void_ptr value);
void it(String text);
void describe(String text);

#endif