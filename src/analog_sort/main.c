#include <lib_sort/arg.h>
#include <lib_sort/startprog.h>

#include <stdio.h>

int main(int argc, char** argv){
    
    start();
	Params params = {NULL, NULL};
	opc(&params, argc, argv);
	return 0;
}
