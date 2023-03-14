#include <stdio.h>

void display()
{
	static int i = 0;
	i++;
	printf("Use static i: %d\n", i);
}
int main(void)
{
	display();
	display();
	display();
	return 0;
}