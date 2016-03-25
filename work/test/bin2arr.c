#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int fd,i,size;
	int count = 0;
	unsigned char buf[1024];

	if (argc < 2){
		printf("Usage:./bin2arr binfile >arrayfile\n");
		return -1;
	}

	fd = open(argv[1],O_RDONLY);
	if(fd<0) {
		printf("Don't open %s,are you sure if exist?\n",argv[1]);
		return -1;
	}

	while(1) {
		size = read(fd,buf,1024);
		for(i=0;i<size;i++)
		{
			printf("0x%02x,",buf[i]& 0xFF);
			count++;
			if(count%16 == 0)
				printf("\n");
		}
		if (size < 1024) break;
	}

	close(fd);
	return 0;
}
