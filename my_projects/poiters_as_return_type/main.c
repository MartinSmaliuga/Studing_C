#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sleep(int milli_seconds)
{
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}
void play()
{
	printf("Game was initialized.\n\n");
	sleep(2000);
	system("cls");
}
void option()
{
	printf("Options to change:\n\n");
	printf("\tVolume\n\n");
	sleep(2000);
	system("cls");
}
void ext()
{
	printf("Goodbye!\n\n");
	sleep(2000);
	system("cls");
}
void(*mainMenu())()
{
	signed long n;
	do
	{
		printf("0:Play\n");
		printf("1:Options\n");
		printf("2:Exit\n\n");
		printf("Choose an action: ");
		scanf("%d", &n);
		system("cls");
	} while (n > 2 || n < 0);
	switch (n)
	{
	case 0:
		return play;
	case 1:
		return option;
	default:
		return ext;
	}
}
int main(void)
{
	void(*action)();
	do
	{
		action = mainMenu();
		action();
	} while (action!=&ext);
	return 0;
}