#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int** xyarr;
	unsigned long* x;
	unsigned long xlength;

	printf("Enter xlength of the array: ");
	scanf("%u", &xlength);
	printf("\n\n");

	xyarr = calloc(xlength, sizeof(int*));
	x = calloc(xlength, sizeof(unsigned));

	for (int i = 0; i < xlength; i++)
	{
		printf("Enter ylength for xlength[%u]: ",i);
		scanf("%u", x+i);
		xyarr[i] = calloc(x[i], sizeof(int));
		printf("\n");
		printf("Enter values:\n");
		for (int j = 0; j < x[i]; j++)
		{
			printf("\t[%u][%u]: ", i, j);
			scanf("%d", *(xyarr+i)+j);
			printf("\n");
		}
	}

	printf("\nInitialization completed!");
	system("cls");

	for (int i = 0; i < xlength; i++)
	{
		printf("x[%u]:", i);
		for (int j = 0; j < x[i]; j++)
		{
			printf("\t%d", xyarr[i][j]);
		}
		printf("\n");

		free(xyarr[i]);

	}
	free(xyarr);
	free(x);

	return 0;
}