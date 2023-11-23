#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("Hello C!\n");
	printf("My PID: %d\n", getpid());

	int count = 0;
	while(1)
	{
		count++;
		printf("count: %d\n", count);
		sleep(15);
	}
	return 0;
}
