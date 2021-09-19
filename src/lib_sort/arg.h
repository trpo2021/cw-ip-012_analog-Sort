#ifndef ARG_H
#define ARG_H

 typedef struct _params{
    char* input;
    char* op;

} Params;


void opc(Params*, int arg, char** argv);

char* get_filename();



#endif
