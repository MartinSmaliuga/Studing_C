#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[16];
	unsigned long age;
} person;

int save(char* filename, person people[]);
int load(char* filename);

int main(void) {
	person people[3] = {{"Jim", 21ul}, {"Tomy", 63ul}, {"Lassy", 42ul}};

	printf("People before save:\n\n");
	for (int i = 0; i < sizeof(people) / sizeof(people[0]); i++) {
		printf("Person #%d: %-16s - %-d\n", i + 1, people[i].name, people[i].age);
	}

	char* filename = "people.bin";

	save(filename, people, sizeof(people) / sizeof(people[0]));
	load(filename);

	return 0;
}

int save(char* filename, person people[], unsigned long n) {
	FILE* file = fopen(filename, "wb");

	if (!file) {
		printf("Error occure while opening file to save\n");
		return 1;
	}

	char* c = (char*) &n;

	for (int i = 0; i < sizeof(n); i++) {
		fputc(*c, file);
		c++;
	}

	printf("\n%zu of %d persons were saved\n", fwrite(people, sizeof(person), n, file), n);

	fclose(file);

	return 0;
}

int load(char* filename) {
	FILE* file = fopen(filename, "rb");

	if (!file) {
		printf("Error occure while openning file to load\n");
		return 1;
	}

	unsigned long n = 0;
	char* c = (char*) &n;

	for (int i = 0; i < sizeof(n); i++) {
		*c = fgetc(file);
		c++;
	}

	person* people = malloc(n*sizeof(person));

	printf("\n%zu of %d persons loaded\n\nPeople after loading:\n\n", fread(people, sizeof(person), n, file), n);

	fclose(file);

	for (int i = 0; i < n; i++) {
		printf("Person #%d: %-16s - %d\n", i + 1, people[i].name, people[i].age);
	}

	return 0;
}