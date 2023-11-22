#include <stdio.h>
#include "math.h"

int main()
{
	int value  = 0;

	value = sum(10, 20);
	printf("value = %d\n", value);

	value = prod(10, 20);
	printf("value = %d\n", value);

	return 0;
}
