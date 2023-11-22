#include <stdio.h>
#include <dlfcn.h>

#include "math.h"

int main()
{

	void* handle = dlopen("libmath.so", RTLD_LAZY);
	
	if(!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
	}

	int (*sum)(int a, int b);
	sum = dlsym(handle, "sum");
	if(!sum)
	{
		fprintf(stderr,"%s\n",dlerror());
	}
	else
	{
		int value = sum(10,20);
		printf("value = %d\n", value);
	}

	dlclose(handle);

	return 0;

}

