#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

int main()
{
	puts("test of wiringpi\n");

	wiringPiSetup();

	int major = 42;
	int minor = 42;
	wiringPiVersion(&major, &minor);
	printf("major:minor: %d:%d\n", major, minor);

	int gpio21  = 21;
	pinMode(gpio21, OUTPUT);

	while(1)
	{
		puts("LED ON");
		digitalWrite(gpio21, 1);
		sleep(10);
		puts("LED OFF");
                digitalWrite(gpio21, 0);
                sleep(10);
	}

	return 0;
}
