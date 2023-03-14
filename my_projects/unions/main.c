#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef union
{
	int x;
	int y;
}union1;
typedef union
{
	char x;
	int y;
}union2;
typedef union
{
	char x;
	int y[5];
}union3;
int main(void)
{
	printf("sizeof(union1) = %d\n", sizeof(union1));
	printf("sizeof(union2) = %d\n", sizeof(union2));
	printf("sizeof(union3) = %d\n", sizeof(union3));
	return 0;
}