#include <lib_sort/arg.h>
#include <lib_sort/sort.h>

#include <string.h>
#include <stdlib.h>

int cmp_register(char* line1, char* line2) {
	return strcmp(line1, line2) < 0;
}

int cmp_register_rev(char* line1, char* line2) {
	return strcmp(line1, line2) > 0;
}

int cmp_noregister(char* line1, char* line2) {
	return strcasecmp(line1, line2) < 0;
}

int cmp_noregister_rev(char* line1, char* line2) {
	return strcasecmp(line1, line2) > 0;
}

void sort(char** lines, int N, int (*funcComp)(char*,char*))
{
	int i, j;

    for (i = 0; i < N - 1; i++) {
        for (j = N - 1; j > i; j--) {
            if (funcComp(lines[j], lines[j - 1])) {
                char* temp = lines[j];
                lines[j] = lines[j - 1];
                lines[j - 1] = temp;
            }
        }
    }
}

void sort_process(char** lines, int N, Params params)
{
    if (params.noregister) {
		if (params.reversed)
        	sort(lines, N, cmp_noregister_rev);
		else
			sort(lines, N, cmp_noregister);
	} else {
		if (params.reversed)
        	sort(lines, N, cmp_register_rev);
		else
			sort(lines, N, cmp_register);
	}
}

char** remove_repeats(char** lines, int* N) {
	int size = *N;
	char** lines2 = calloc(sizeof(char*), size);
	int count = 0;
	lines2[0] = lines[0];
	for (int i = 0; i < size; i++) {
		if (strcmp(lines[i], lines2[count]) != 0)
			lines2[++count] = lines[i];
	}
	*N = count+1;
	return lines2;
}
