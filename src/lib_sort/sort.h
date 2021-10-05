#ifndef SORT_H
#define SORT_H

#include <lib_sort/arg.h>

void sort(char** lines, int N, int (*funcComp)(char*, char*));

void sort_process(char** lines, int N, Params params);

char** remove_repeats(char** lines, int* N);

#endif // #ifndef SORT_H
