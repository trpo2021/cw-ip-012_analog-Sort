#include <lib_sort/processfile.h>

#include <ctest.h>
#include <string.h>
#include <stdlib.h>

CTEST(suite_processfile, get_line)
{
    FILE* fin = fopen("test/file_test.txt", "r");
    if (fin == NULL){
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
    ASSERT_STR("Math file my program word", line3);
    
    fclose(fin);
    fclose(line);
    fclose(line2);
    fclose(line3);
    fclose(line4);
    
}
CTEST(suite_processfile, get_lines_from_file)
{
}
