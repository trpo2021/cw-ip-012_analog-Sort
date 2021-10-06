#ifndef SORT_H
#define SORT_H

#include <lib_sort/arg.h>

int cmp_register(char*, char*);
int cmp_register_rev(char*, char*);
int cmp_noregister(char*, char*);
int cmp_noregister_rev(char*, char*);

void sort(char** lines, int N, int (*funcComp)(char*, char*));

void sort_process(char** lines, int N, Params params);

char** remove_repeats(char** lines, int* N);
char** remove_repeats_noreg(char** lines, int* N);

#endif // #ifndef SORT_H
