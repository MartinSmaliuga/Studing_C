#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef union
{
	unsigned char ch;
	struct
	{
		unsigned int a0 : 1;
		unsigned int a1 : 1;
		unsigned int a2 : 1;
		unsigned int a3 : 1;
		unsigned int a4 : 1;
		unsigned int a5 : 1;
		unsigned int a6 : 1;
		unsigned int a7 : 1;
	};
} charBitField;

int main(void)
{
	unsigned long long _long_long = 18436744063702851415;
	unsigned long* _long = &_long_long;
	unsigned short* _short = _long;
	unsigned char* _char = _long;

	printf("unsigned long long value: %#llx\t adress: %p\n\n\n", _long_long, &_long_long);

	for (int i = 0; i < 2; i++)
	{
		printf("unsigned long value: %#x\t adress: %p\n", *(_long+i), _long+i);
	}
	printf("\n\n");

	for (int i = 0; i < 4; i++)
	{
		printf("unsigned short value: %#x\t adress: %p\n", *(_short + i), _short + i);
	}
	printf("\n\n");

	for (int i = 0; i < 8; i++)
	{
		printf("unsigned char value: %#x\t adress: %p\n", *(_char + i), _char + i);
		charBitField ch;
		ch.ch = *(_char + i);
		printf("  charBitField value: %#x\tbit7: %u\tbit6: %u\tbit5: %u\tbit4: %u\tbit3: %u\tbit2: %u\tbit1: %u\tbit0: %u\n", ch.ch, ch.a7, ch.a6, ch.a5, ch.a4, ch.a3, ch.a2, ch.a1, ch.a0);
		printf("\n");
	}
	printf("\n");

	return 0;
}