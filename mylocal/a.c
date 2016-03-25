#include <assert.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	//assert(0);
	printf("%ld\n",sysconf(_SC_PAGESIZE));
	printf("%ld\n",sysconf(_SC_OPEN_MAX));
	printf("%ld\n",sysconf(_SC_VERSION));
	return 0;
}
