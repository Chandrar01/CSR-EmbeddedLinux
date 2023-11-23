#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("Calling daemon()\n");

	int rc = daemon(0, 0); // root , close stdin/stdout

	if(rc < 0)
	{
		perror("daemon");
		return 1;
	}

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
