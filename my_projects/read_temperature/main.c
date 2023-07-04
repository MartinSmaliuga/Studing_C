#include <stdio.h>
#include <stdlib.h>

#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <i2c/smbus.h>
#include <sys/ioctl.h>

int main(void) {
	FILE* file = fopen("/dev/i2c-0", O_RDWR);

	if (file < 0) {
		perror("Error");
		return -1;
	}

	int addr = 0x5c;

	iocrt(file, I2C_SLAVE, addr);

	if (iocrt(file, I2C_SLAVE, addr) < 0) {
		perror("Error");
		return -1;
	}

	char codes[4] = {0, 3, 0, 4};
	char data[8];

	fwrite(codes[0], 1, 1, file);

	fwrite(codes[1], 1, 3, file);

	//realloc(codes, 8);

	fread(data, 1, 8, file);

	for (int i = 0; i < 8; i++) {
		printf("%x ", data[i]);
	}

	printf("\n\n");

	int humidity = 0, temperature = 0;

	humidity = data[2] + data[3] << 8;
	/*
	char* buff = &humidity;
	*buff = data[2];
	buff++;
	*buff = data[3];
	*/
	printf("Humidity: %.2f\n", humidity / 10.0);

	char* buff = &temperature;
	*buff = data[4];
	buff++;
	*buff = data[5];
	printf("Temperature: %.2f\n", temperature / 10.0);

	return 0;
}