#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char name[16];
	unsigned long age;
} person;

int save_struct(char *filename, person * pp)
{
	unsigned long persons_number = sizeof(pp) / sizeof(person);
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		perror("Unable to open file %s", filename);
		return 1;
	}

	printf("People to save:\n\n");
	for (int i = 0; i < persons_number; i++)
	{
		printf("Person %u:\n", i + 1);
		printf("\tName: %s\n", pp[i].name);
		printf("\tAge: %u\n", pp[i].age);
	}

	char* bp = (char*) &persons_number;
	unsigned long size = sizeof(persons_number);

	while (size != 0)
	{
		putc(*bp, fp);
		bp++;
		size--;
	}

	bp = (char*) pp;
	size = sizeof(person)*persons_number;

	while (size!=0)
	{
		putc(*bp, fp);
		bp++;
		size--;
	}

	bp = NULL;
	fclose(fp);
	return 0;
}

int load_struct(char *filename)
{
	FILE* fp = fopen(filename, "rb");
	unsigned long size = sizeof(unsigned long);

	unsigned long amount;
	char* bp = &amount;

	while (size != 0)
	{
		*bp = getc(fp);
		bp++;
		size--;
	}

	person* people = calloc(amount, sizeof(person));
	size = sizeof(people);
	bp = (char*) people;

	while (size != 0)
	{
		*bp = getc(fp);
		bp++;
		size--;
	}

	printf("%u person founded:\n\n", amount);

	for (int i = 0; i < amount; i++)
	{
		printf("%-u:\t%-s\t%-u\n", i + 1, people[i].name, people[i].age);
	}
}
int main(void)
{
	person* pp = calloc(3, sizeof(person));
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
			case 0:
				(pp+i)->name = "";

				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;
		}
	}
	char* filename = "save.dat";
	save_struct(filename, pp);
	load_struct(filename);

	return 0;
}