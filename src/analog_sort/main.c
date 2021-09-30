#include <lib_sort/arg.h>
#include <lib_sort/processfile.h>
#include <lib_sort/startprog.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    start();
    Params params = {NULL, NULL};
    opc(&params, argc, argv);

    FILE* fin;
    if (params.input != NULL) {
        fin = fopen(params.input, "r");
    } else {
        exit(EXIT_FAILURE);
    }
    char** lines = get_lines_from_file(fin);

    printf("line0: %s\n", lines[0]);
    printf("line1: %s\n", lines[1]);
    printf("line2: %s\n", lines[2]);
    printf("line3: %s\n", lines[3]);
    printf("line4: %s\n", lines[4]);
    printf("line5: %s\n", lines[5]);

    return 0;
}
