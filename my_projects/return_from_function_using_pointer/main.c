#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void operations(int x, int y, int* z, char op)
{

	printf("Operations input data:\n\tx: %d\n\ty: %d\n\tz: %p\n\t  *z: %d\n\top: %c\n\t  ASCII code:%d\n", x, y, z, *z, op, op);
	switch (op)
	{
	case 43:
		*z = x + y;
		printf("Addition performed!\n");
		break;
	case 45:
		*z = x - y;
		printf("Substraction performed!\n");
		break;
	case 42:
		*z = x * y;
		printf("Multiplication performed!\n");
		break;
	case 47:
		*z = x / y;
		printf("Dividing performed!\n");
		break;
	default:
		*z = 0;
		printf("Nothing performed!\n");
		break;
	}
}
int main(void)
{
	int a = 1, b = 2, c = 32;
	operations(a, b, &c, '+');
	printf("%d + %d = %d\n\n", a, b, c);
	operations(a, b, &c, '-');
	printf("%d - %d = %d\n\n", a, b, c);
	operations(a, b, &c, '*');
	printf("%d * %d = %d\n\n", a, b, c);
	operations(a, b, &c, '/');
	printf("%d / %d = %d\n\n", a, b, c);
	return 0;
}