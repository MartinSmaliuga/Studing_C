#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
void menuPrinter(char* menuname, int n, ...)
{
	printf("%s:\n\n", menuname);
	va_list points;
	va_start( points, n);
	for (int i = 1; i <= n; i++)
	{
		printf("  %d: ", i);
		char* point = va_arg(points, char*);
		while (*point)
		{
			printf("%c", *point);
			point++;
		}
		printf("\n");
	}
	va_end(points);
}
int main(void)
{
	menuPrinter("Main menu", 3, "Play", "Options", "Exit");
	return 0;
}