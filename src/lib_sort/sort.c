#include <lib_sort/sort.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(){
    int a;
    char ch, st[80];
    FILE *f1;
    //программа сортирует слова в файле и выводит результат на экран
    printf ("__Program analog_sort__\n");
    printf( "vvedite filename: \n");
    scanf("%c", &st);
    f1=fopen("%c", st);
      while((ch=fgetc(f1))!=EOF)
      {
	printf("%c", ch);
	}
	
}
