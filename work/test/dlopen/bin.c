/*
 * Author : ZhongHuiping
 * Email : zhonghuiping@tydtech.com
 * Last modified : 2014-11-13 17:16
 * Filename : bin.c
 * Description : 
 */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	void * hal;
	int (*fun)(int a,int b);
	int (*pr)(char *str);
	char *error;
	hal = dlopen(LIB_FILE,RTLD_LAZY);
	if (!hal) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	dlerror(); 
	pr = dlsym(hal,"print");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}
	pr("Hello,world");

	fun = dlsym(hal,"add");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}
	printf("%d + %d = %d\n",5,4,fun(5,4));

	fun = dlsym(hal,"mul");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}
	printf("%d * %d = %d\n",5,4,fun(5,4));

	return 0;
}

