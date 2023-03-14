#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	unsigned int age;
	char name[30];
}person;

person* createPerson()
{
	person user;
	printf("Enter person name: ");
	scanf("%s", &(user.name));
	printf("Enter person age: ");
	scanf("%u", &(user.age));
	system("cls");
	return &user;
}

int main(void)
{
	person N;
	N = *createPerson();
	printf("Person name: %s\tPerson age: %u", N.name, N.age);
	return 0;
}