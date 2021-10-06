#include <lib_sort/processfile.h>

#include <ctest.h>
#include <stdlib.h>
#include <string.h>

CTEST(suite_processfile, get_line)
{
    FILE* fin = fopen("test/file_test.txt", "r");
    if (fin == NULL) {
        fprintf(stderr, "Error! Can't open test/file_test.txt");
        ASSERT_NOT_NULL(fin);
    }

    char* line = get_line(fin);
    ASSERT_STR("   ", line);

    char* line2 = get_line(fin);
    ASSERT_STR("", line2);

    char* line3 = get_line(fin);
    ASSERT_STR("Math file", line3);

    char* line4 = get_line(fin);
    ASSERT_STR("Math file my program word", line4);

    fclose(fin);
    free(line);
    free(line2);
    free(line3);
    free(line4);
}
CTEST(suite_processfile, get_lines_from_file)
{
    FILE* fin = fopen("test/file_test.txt", "r");
    if (fin == NULL) {
        fprintf(stderr, "Error! Can't open test/file_test.txt");
        ASSERT_NOT_NULL(fin);
    }

    int N;

    char** lines = get_lines_from_file(fin, &N);
    ASSERT_STR("   ", lines[0]);

    ASSERT_EQUAL(11, N);

    ASSERT_STR("Math file", lines[1]);

    ASSERT_STR("Math file my program word", lines[2]);

    ASSERT_STR("1235", lines[3]);

    ASSERT_STR("katalog", lines[4]);

    ASSERT_STR("process", lines[5]);

    for (int i = 0; i < N; i++)
        free(lines[i]);
    fclose(fin);

    FILE* fin2 = fopen("test/empty.txt", "r");

    ASSERT_NOT_NULL(fin2);

    lines = get_lines_from_file(fin, &N);

    ASSERT_EQUAL(0, N);

    fclose(fin2);
}
