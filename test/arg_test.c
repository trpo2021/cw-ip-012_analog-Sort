#include <lib_sort/arg.h>

#include <ctest.h>
#include <stdlib.h>
#include <string.h>

CTEST(suite_arg, opc)
{
    Params params = {NULL, NULL, 0, 0, 0};

    char** argv = calloc(sizeof(char*), 4);
    argv[0] = "progname";
    argv[1] = "-f";
    argv[2] = "input.txt";
    argv[3] = "-r";
    opc(&params, 4, argv);

    ASSERT_STR("input.txt", params.input);
    ASSERT_NULL(params.output);
    ASSERT_EQUAL(1, params.reversed);
    ASSERT_EQUAL(0, params.noregister);
    ASSERT_EQUAL(0, params.norepeats);

    free(argv);
}
