#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("Hello C!\n");
	printf("My PID: %d\n", getpid());

	printf("Press ENTER to end: ");
	getchar();

	return 0;
}
