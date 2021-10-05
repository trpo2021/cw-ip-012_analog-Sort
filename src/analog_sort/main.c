#include <lib_sort/arg.h>
#include <lib_sort/processfile.h>
#include <lib_sort/startprog.h>
#include <lib_sort/sort.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    start();
    Params params = {NULL, NULL, 0, 0, 0};
    opc(&params, argc, argv);

    FILE* fin;
    if (params.input != NULL) {
        fin = fopen(params.input, "r");
    } else {
        exit(EXIT_FAILURE);
    }
    int N;
	char** lines = get_lines_from_file(fin, &N);

	for (int i = 0; i < N; i++)
		printf("%2d: %s\n", i, lines[i]);

	sort(lines, N);

	printf("Sorted\n");
	for (int i = 0; i < N; i++)
		printf("%2d: %s\n", i, lines[i]);

    return 0;
}
