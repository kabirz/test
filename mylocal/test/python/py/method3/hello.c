#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int hello()
{
	char a[128];
	int fd;
	fd = open("a.txt",O_RDONLY);
	printf("Hello,world!\n");
	int i=read(fd,a,128);
	a[i] = '\0';
	printf("%s\n",a);
	return 0;
}
