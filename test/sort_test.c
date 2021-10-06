#include <lib_sort/processfile.h>
#include <lib_sort/sort.h>

#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CTEST(suite_sort, cmp_register)
{
    int result;

    result = cmp_register("abc", "bcd");
    ASSERT_EQUAL(1, result);

    result = cmp_register("abc", "abc");
    ASSERT_EQUAL(0, result);

    result = cmp_register("abc", "aaa");
    ASSERT_EQUAL(0, result);

    result = cmp_register("Aaa", "aaa");
    ASSERT_EQUAL(1, result);
}

CTEST(suite_sort, cmp_register_rev)
{
    int result;

    result = cmp_register_rev("abc", "bcd");
    ASSERT_EQUAL(0, result);

    result = cmp_register_rev("abc", "abc");
    ASSERT_EQUAL(0, result);

    result = cmp_register_rev("abc", "aaa");
    ASSERT_EQUAL(1, result);

    result = cmp_register_rev("Aaa", "aaa");
    ASSERT_EQUAL(0, result);
}

CTEST(suite_sort, cmp_noregister)
{
    int result;

    result = cmp_noregister("abc", "bcd");
    ASSERT_EQUAL(1, result);

    result = cmp_noregister("abc", "abc");
    ASSERT_EQUAL(0, result);

    result = cmp_noregister("abc", "aaa");
    ASSERT_EQUAL(0, result);

    result = cmp_noregister("Aaa", "aaa");
    ASSERT_EQUAL(0, result);
}

CTEST(suite_sort, cmp_noregister_rev)
{
    int result;

    result = cmp_noregister_rev("abc", "bcd");
    ASSERT_EQUAL(0, result);

    result = cmp_noregister_rev("abc", "abc");
    ASSERT_EQUAL(0, result);

    result = cmp_noregister_rev("abc", "aaa");
    ASSERT_EQUAL(1, result);

    result = cmp_noregister_rev("Aaa", "aaa");
    ASSERT_EQUAL(0, result);
}

CTEST(suite_sort, sort)
{
    FILE* fin = fopen("test/file_test.txt", "r");
    ASSERT_NOT_NULL(fin);
    int N;
    char** lines = get_lines_from_file(fin, &N);

    sort(lines, N, cmp_register_rev);

    ASSERT_STR("process", lines[0]);
    ASSERT_STR("katalog", lines[1]);
    ASSERT_STR("Math file my program word", lines[2]);

    sort(lines, N, cmp_noregister_rev);
    ASSERT_STR("process", lines[0]);
    ASSERT_STR("Math file my program word", lines[1]);
    ASSERT_STR("Math file", lines[2]);

    for (int i = 0; i < N; i++)
        free(lines[i]);
    free(lines);
}

CTEST(suite_sort, remove_repeats)
{
    char** lines = calloc(sizeof(char*), 5);
    lines[0] = "help";
    lines[1] = "word";
    lines[2] = "hello";
    lines[3] = "hello";
    lines[4] = "math";

    int N = 5;
    char** new_lines = remove_repeats(lines, &N);

    ASSERT_EQUAL(4, N);
    ASSERT_STR("help", new_lines[0]);
    ASSERT_STR("word", new_lines[1]);
    ASSERT_STR("hello", new_lines[2]);
    ASSERT_STR("math", new_lines[3]);

    free(lines);
}

CTEST(suite_sort, remove_repeats_noreg)
{
    char** lines = calloc(sizeof(char*), 5);
    lines[0] = "help";
    lines[1] = "word";
    lines[2] = "Hello";
    lines[3] = "hello";
    lines[4] = "math";

    int N = 5;
    char** new_lines = remove_repeats_noreg(lines, &N);

    ASSERT_EQUAL(4, N);
    ASSERT_STR("help", new_lines[0]);
    ASSERT_STR("word", new_lines[1]);
    ASSERT_STR("Hello", new_lines[2]);
    ASSERT_STR("math", new_lines[3]);

    free(lines);
}
