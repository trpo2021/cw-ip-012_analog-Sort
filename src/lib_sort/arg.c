#include <lib_sort/arg.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help()
{
    printf("Доступные аргументы:\n"
           "-f <file>\t--\tимя файла на входе\n"
           "-o <file>\t--\tимя файла на выходе\n"
           "-r <file>\t--\tсортировать в обратном порядке\n"
           "-i <file>\t--\tотключить чувствительность к регистру\n"
           "-u <file>\t--\tудалить повторяющиеся строки\n");
}

void print_wrong_arg()
{
    printf("Ошибка! Повторный аргумент!\n\n");
}

void opc(Params* params, int argc, char** argv)
{
    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            print_help();
            exit(EXIT_SUCCESS);
        }
    }
    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
            case 'f':
                if (params->input != NULL) {
                    print_wrong_arg();
                    print_help();
                    exit(EXIT_FAILURE);
                }
                params->input = argv[++i];
                break;
            case 'o':
                if (params->output != NULL) {
                    print_wrong_arg();
                    print_help();
                    exit(EXIT_FAILURE);
                }
                params->output = argv[++i];
                break;
            case 'r':
                params->reversed = 1;
                break;
            case 'i':
                params->noregister = 1;
                break;
            case 'u':
                params->norepeats = 1;
                break;
            default:
                printf("Неверный аргумент: %s\n", argv[i]);
                exit(EXIT_FAILURE);
            }
        }
    }
}
