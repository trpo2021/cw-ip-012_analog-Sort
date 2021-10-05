#include <lib_sort/sort.h>

#include <string.h>

void sort(char** lines, int N)
{
    int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = N - 1; j > i; j--) {
            if (strcmp(lines[j], lines[j - 1]) < 0) {
                char* temp = lines[j];
                lines[j] = lines[j - 1];
                lines[j - 1] = temp;
            }
        }
    }
}
