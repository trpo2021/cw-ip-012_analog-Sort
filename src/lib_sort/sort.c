#include <lib_sort/sort.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(){
    int i, j = 0, n=0; char m[20][40];
    char st [80];
    
    FILE* f1;
    //программа сортирует слова в файле и выводит результат на экран
    printf ("__Program analog_sort__\n");
    printf( "vvedite filename: \n");


//ввод имени файла
    //scanf("%s", &st);
    //f1=fopen("%c", st);
    f1 = fopen ("/home/perminov/Рабочий стол/001.txt", "r");
    	while (fgets (st, 80, f1)){
		for (i=0; i<80; i++){
			if(st[i]!=' '&&st[i]!=','&&st[i]!='\n')
				m[n][j++]=st[i];
			if(st[i+1]==' ' /*|| st[i+1] == '\n' && st[i] !=' '*/){
				m[n][j]=0; n++; j=0;	
				}
            }
        }
    fclose(f1);

  //для сортировки слов по алфавиту будем испльзовать индексный массив
    int t, ind[n];
    
    for (i=0; i<n; i++)
    for (j=n-1; j>i; j++){
        if (m[j][0]<m[j-1][0])
            t=ind[j];
            ind[j]=ind[j-1];
            ind[j-1]=t;
                    
}
    for (i=0; i<n;i++){
        for (j=0; j>0; j++)
        printf("%")  
    }
    
                        
        
   for (i=0; i<n; i++)
	puts(m[ind[i]]);
	
}
