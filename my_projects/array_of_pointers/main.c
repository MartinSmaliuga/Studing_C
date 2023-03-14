#include <stdio.h>

int add(int x, int y)
{
	printf("Function add was called with parameters: x = %d, y = %d\n", x, y);
	return x + y;
}
int substract(int x, int y)
{
	printf("Function substract was called with parameters: x = %d, y = %d\n", x, y);
	return x - y;
}

int main(void)
{
	int a = 1, b = 2;
	int (*operation[])(int, int) = {add, substract};
	int size = sizeof(operation)/sizeof(operation[0]);
	for (int i = 0; i < size; i++)
	{
		printf("The result of the call: operation[%d](%d,%d): %d\n\n", i, a, b, operation[i](a,b));
	}
	return 0;
}