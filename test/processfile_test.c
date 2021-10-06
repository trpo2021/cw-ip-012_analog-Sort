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
    FILE *fin = fopen("test/file_test.txt", "r");
    if (fin == NULL) {
        fprintf(stderr, "Error! Can't open test/file_test.txt");
        ASSERT_NOT_NULL(fin);
    }

    
    int N;
    
    char **lines = get_lines_from_file(fin, &N);     
    ASSERT_STR("   ", lines[0]);
    ASSERT_EQUAL(11,N);
    
    
    ASSERT_STR("Math file", lines1[1]);
   
    ASSERT_STR("Math file my program word", lines2[2]);
      
    ASSERT_STR("1235", lines3[3]);

    ASSERT_STR("katalog", lines4[4]);

    ASSERT_STR("process", lines5[5]);
    
}
