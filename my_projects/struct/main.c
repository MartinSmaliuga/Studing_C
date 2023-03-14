#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	unsigned int age;
	char name[30];
}person;
int main(void)
{
	person N;
	printf("Enter your name: ");
	scanf("%s", N.name);
	printf("Enter your age: ");
	scanf("%u", &N.age);
	printf("Name: %s\tAge: %u", N.name, N.age);
	return 0;
}