#ifndef PROCESSFILE_H
#define PROCESSFILE_H

#include <stdio.h>

char* get_line(FILE*);

char** get_lines_from_file(FILE*, int* N);

#endif // #ifndef PROCESSFILE_H
