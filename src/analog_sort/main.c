#include <lib_sort/arg.h>
#include <lib_sort/processfile.h>
#include <lib_sort/sort.h>
#include <lib_sort/startprog.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    start();
    printf("\n");
    Params params = {NULL, NULL, 0, 0, 0};
    opc(&params, argc, argv);

    FILE *fin, *fout;
    if (params.input != NULL) {
        fin = fopen(params.input, "r");
    } else {
        exit(EXIT_FAILURE);
    }
    if (params.output != NULL) {
        fout = fopen(params.output, "w");
    } else {
        fout = stdout;
    }
    int N;
    char** lines = get_lines_from_file(fin, &N);

    printf("Файл %s\n\n", params.input);
    for (int i = 0; i < N; i++)
        printf("%s\n", lines[i]);

    sort_process(lines, N, params);

    if (params.norepeats)
        lines = remove_repeats(lines, &N);

    if (params.output)
        printf("\nЗаписано в %s\n", params.output);
    else
        printf("\nВывод:\n\n");
    for (int i = 0; i < N; i++) {
        fprintf(fout, "%s\n", lines[i]);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
