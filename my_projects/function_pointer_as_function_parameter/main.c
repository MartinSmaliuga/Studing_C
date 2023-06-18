#include <stdio.h>

int isPositive(int x)
{
	return x > 0;
}

int isNegative(int x)
{
	return x < 0;
}

int isEven(int x)
{
	return x % 2 == 0;
}

int isOdd(int x)
{
	return x % 2 != 0;
}

void numsChecker(int (*checker)(int), int nums[], int size)
{
	for (int i = 0; i != size; i++)
	{
		if (checker(nums[i]) != 0)
		{
			printf("%d\t", nums[i]);
		}
	}
	printf("\n");
}

int main(void)
{
	int nums[] = { -3, -2, -1, 0, 1, 2, 3};
	int size = sizeof(nums) / sizeof(nums[0]);
	printf("Numbers: ");
	for (int i = 0; i != size; i++)
	{
		printf("%d\t", nums[i]);
	}

	printf("\n\n");

	int (*check_list[])(int) = {isPositive, isNegative, isOdd, isEven};

	char* strings[] = {"Positive numbers: ", "Negative numbers: ", "Odd numbers: ", "Even numbers: "};

	for (int i = 0; i < sizeof(check_list) / sizeof(check_list[0]); i++) {
		printf("%s", strings[i]);
		numsChecker(check_list[i], nums, size);
		printf("\n");
	}

	return 0;
}