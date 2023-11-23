/* Connect Led to GPIO 21 and make it blink */


#include <stdio.h>
#include <pigpio.h>
#include <signal.h>
#include <unistd.h>

#define LED_PIN 21

int running = 1;
void handle_sig_int(int sig)
{
        running = 0;
}

int main()
{
        int result = gpioInitialise();
        if(result<0)
        {
                fprintf(stderr, "gpioInitialise failed\n");
                result  = 1;
                goto getOut;
        }

        result = gpioSetMode(LED_PIN, PI_OUTPUT);
        if(result<0)
        {
                fprintf(stderr,"gpioSetMode() failed\n");
                result = 2;
                goto getOut;
        }
        // We need to use Signals
        int cfg = gpioCfgGetInternals();
        cfg |= PI_CFG_NOSIGHANDLER;
        gpioCfgSetInternals(cfg);

        signal(SIGINT, handle_sig_int);

        int toggle = 1;
        while(running)
        {
                sleep(15);
                result = gpioWrite(LED_PIN, toggle);
                if(result < 0) break;
                toggle ^= 1;

        }

getOut:
        gpioTerminate();
        return result;

}
