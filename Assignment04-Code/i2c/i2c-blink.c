/* i2c-blink.c
 * blink leds connected to i2c device 
 * TO BUILD: gcc -Wall -o i2c-blink i2c-blink.c -lpigpio -lrt
 * TO RUN:  sudo ./i2c-blink
*/

#include <stdio.h>
#include <pigpio.h>
#include <signal.h>
#include <unistd.h>

#define MCP23008_I2C_ADDR 0x20

int running = 1;
void handle_sig_int(int sig)
{
	running = 0;
}

int main()
{
	int result = gpioInitialise();

	if(result < 0)
	{
		fprintf(stderr, "gpioInitialise() failed\n");
		result = 1;
		goto getOut;

	}

	// We need to use signals
	int cfg = gpioCfgGetInternals();
	cfg |= PI_CFG_NOSIGHANDLER;
	gpioCfgSetInternals(cfg);

	signal(SIGINT, handle_sig_int);

	unsigned i2cBus = 1;
	unsigned i2cAddr = MCP23008_I2C_ADDR;
	unsigned i2cFlags = 0;

	int i2cHandle = i2cOpen(i2cBus, i2cAddr, i2cFlags);
	if(i2cHandle < 0)
	{
		fprintf(stderr,"i2cOpen() failed\n");
		goto getOut;
	}

	// Set MCP23008 I/O direction for all pins as output (0x00)
	unsigned i2cReg = 0;
	unsigned i2cValue = 0;

	result = i2cWriteByteData(i2cHandle, i2cReg, i2cValue);
	if(result < 0)
	{
                fprintf(stderr,"i2cWriteByteData() failed\n");
                goto getOut;
        }

	// tpggle the pins connected to MCP23008 I/0 expander
	i2cReg = 0x09;
	while(1)
	{
		i2cValue = 0xff;
		i2cWriteByteData(i2cHandle, i2cReg, i2cValue);
		sleep(5);
		i2cValue = 0x00;
		i2cWriteByteData(i2cHandle, i2cReg, i2cValue);
                sleep(5);
	}

getOut:
	if(i2cHandle >= 0) i2cClose(i2cHandle);
	gpioTerminate();
	return 0;
}
