#include <lib_sort/processfile.h>

#include <stdlib.h>
#include <stdio.h>

char* get_line(FILE* fin) {
	int maxsymb = 4;
	char* line = calloc(sizeof(char), maxsymb);

	char c;
	int i;
	for (i = 0; (c = getc(fin)) != EOF && c != '\r' && c != '\n'; i++) {
		if (i >= maxsymb-1) {
			maxsymb *= 2;
			char* newline = realloc(line, maxsymb);
			if (newline == NULL) {
				printf("Ошибка выделения памяти!\n");
				exit(EXIT_FAILURE);
			}
			line = newline;
		}
		line[i] = c;
	}
	line[i] = '\0';

	if (c == EOF && i == 0)
		return NULL;
	return line;
}

char** get_lines_from_file(FILE* fin) {
	int count = 0;
	int maxline = 2;
	char* line;
	char** lines = calloc(sizeof(char*), maxline);
	while (1) {
		if (count > maxline-1) {
			maxline *= 2;
			char** newlines = realloc(lines, maxline*sizeof(char*));
			if (newlines == NULL) {
				printf("Ошибка выделения памяти\n");
				exit(EXIT_FAILURE);
			}
			lines = newlines;
		}
		line = get_line(fin);
		if (line == NULL)
			break;
		// if empty
		if (line[0] == '\0')
			continue;
		lines[count++] = line;
	}
	return lines;
}
