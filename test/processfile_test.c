#include <lib_sort/processfile.h>

#include <ctest.h>
#include <string.h>
#include <stdlib.h>

CTEST(suite_processfile, get_line)
{
    FILE* fin = fopen("test/file_test.txt", "r");
    if (fin == NULL){
        fprintf(stderr, "Error! Can't open test/file_test.txt");
    }
    
    char* line = get_line(fin);
    check_str("   ", line);

    char* line2 = get_line(fin);
    check_str("", line2);

    char* line3 = get_line(fin);
    check_str("Math file", line3);
    
    fclose(fin);
    fclose(line);
    fclose(line2);
    fclose(line3);
    
    
}
CTEST(suite_processfile, get_lines_from_file)
{
}
