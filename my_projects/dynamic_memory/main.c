#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	unsigned int age;
	char name[30];
}person;

person* createPerson(person* user)
{
	printf("Enter person name: ");
	scanf("%s", &(user->name));
	printf("Enter person age: ");
	scanf("%u", &(user->age));
	system("cls");
	return user;
}

person* createPeople(unsigned long n)
{
	person* people = calloc(n, sizeof(person));
	for (int i = 0; i < n; i++)
	{
		createPerson(people+i);
	}
	return people;
}

void showPerson(person* user)
{
	printf("User name: %s\nUser age: %u\n\n", user->name, user->age);
}

void showPeople(person* people, int n)
{
	for (int i = 0; i < n; i++)
	{
		showPerson(people+i);
	}
}

int main(void)
{
	int n = 2;
	person* people = createPeople(n);
	showPeople(people, n);
	free(people);
	return 0;
}