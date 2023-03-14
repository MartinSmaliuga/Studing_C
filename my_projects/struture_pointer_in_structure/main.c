#include <stdio.h>

struct person
{
    int age;
    char* name;
} tom;

int main(void)
{
    tom = { 38, "Tom" };
    printf("Name:%s \t Age: %d", tom.name, tom.age);
    return 0;
}