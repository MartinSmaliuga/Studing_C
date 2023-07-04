#define _CRT_SECURE_NO_WARNINGS
#define NAME_LENGTH 16
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[NAME_LENGTH];
    unsigned long age;
} Person;

Person* clear_name_from_lf(Person*);

int main(void)
{
    Person *p = malloc(sizeof(Person));

    fputs("Enter your name: ", stdout);

    if (fgets(p->name, NAME_LENGTH, stdin) == NULL) {
        fputs("\nUnable to read your name...\n", stderr);
        return 1;
    }

    p = clear_name_from_lf(p);

    fputs("Your name is: ", stdout);
    fputs(p->name, stdout);

    fputs("\n\nEnter your age: ", stdout);

    char* input = malloc(5);

    if (fscanf(stdin, "%lu", &(p->age)) == 0) {
        fputs("Invalid input was given...\n", stderr);
        return 2;
    }

    fputs("Your age is: ", stdout);
    fprintf(stdout, "%d\n", p->age);

    fputs("\nData in struct:\n", stdout);
    fprintf(stdout, "Name: %s\nAge %d\n", p->name, p->age);

    fputs("\nMemory dump:\n", stdout);
    fwrite(p, sizeof(Person), 1, stdout);

    return 0;
}

Person* clear_name_from_lf(Person* p) {
    for (int i = 0; i < NAME_LENGTH; i++) {
        if (*(p->name + i) == '\n')
            *(p->name + i) = NULL;
    }

    return p;
}