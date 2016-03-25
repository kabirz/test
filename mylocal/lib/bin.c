#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	void * hal;
	int (*fun)(int a,int b);
	int (*pr)(char *str);
	char *error;
	int tmp;
	hal = dlopen(LIB_FILE,RTLD_LAZY);
	if (!hal) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	dlerror(); 
	pr = dlsym(hal,"print");
	fun = dlsym(hal,"add");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}

	 tmp=*((int *)dlsym(hal,"gol"));

	pr("Hello,world");
	printf("s + b = %d,gol=%d\n",fun(5,4),tmp);

	return 0;
}
