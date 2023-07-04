#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char* str1 = "Hello";
	char* str2 = "Hello";

	fprintf(stdout, "First string: %s\n", str1);
	fprintf(stdout, "Second string: %s\n", str2);
	fprintf(stdout, "strcmp return: %d\n\n", strcmp(str1, str2));

	str2 = "hello";

	fprintf(stdout, "First string: %s\n", str1);
	fprintf(stdout, "Second string: %s\n", str2);
	fprintf(stdout, "strcmp return: %d\n\n", strcmp(str1, str2));

	str2 = "Eello";

	fprintf(stdout, "First string: %s\n", str1);
	fprintf(stdout, "Second string: %s\n", str2);
	fprintf(stdout, "strcmp return: %d\n\n", strcmp(str1, str2));

	int s1 = 30;
	int s2 = 30;
	str1 = calloc(s1, 1);
	str2 = calloc(s2, 1);
	strcat(str1, "Hello");
	strcat(str2, " World!");

	fprintf(stdout, "First string: %s\nFirst string size: %d\n", str1, s1);
	fprintf(stdout, "Second string: %s\nSecond string size: %d\n", str2, s2);
	fprintf(stdout, "First string pointer: %p\nstrcat return: %p\n", str1, strcat(str1, str2));
	fprintf(stdout, "First string after strcat: %s\n\n", str1);

	s1 = 2;
	s2 = 30;
	str1 = calloc(s1, 1);
	str2 = calloc(s2, 1);
	strcpy(str1, "Hello");
	strcpy(str2, " World!");

	fprintf(stdout, "First string: %s\nFirst string size: %d\n", str1, s1);
	fprintf(stdout, "Second string: %s\nSecond string size: %d\n", str2, s2);
	fprintf(stdout, "First string pointer: %p\nstrcat return: %p\n", str1, strcat(str1, str2));
	fprintf(stdout, "First string after strcat: %s\n\n", str1);



	return 0;
}