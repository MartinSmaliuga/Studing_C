#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	fputs("Enter string: ", stdout);

	if (fgetc(stdin) == '\n') {
		fputs("Write not empty string!\n", stderr);
		return 1;
	}

	fseek(stdin, -1, SEEK_END);
	fseek(stdin, 0, SEEK_SET);

	fputs("First character in stream stdin after double using of fseek: ", stdout);
	fprintf(stdout, "%c\n", fgetc(stdin));

	rewind(stdin);

	fputs("\nEnter another string: ", stdout);

	if (fgetc(stdin) == '\n') {
		fputs("Write not empty string!\n", stderr);
		return 1;
	}

	fseek(stdin, -1, SEEK_END);
	fputs("Last character in stream stdin after using of fseek: ", stdout);
	fprintf(stdout, "%c\n", fgetc(stdin));

	return 0;
}