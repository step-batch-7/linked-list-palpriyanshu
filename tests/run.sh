#! /bin/bash
executable=$1
rm -rf *.o
gcc -c tests.c ../list.c run_test.c test_lib.c
gcc -o $1 *.o
./$1
rm -rf *.o test