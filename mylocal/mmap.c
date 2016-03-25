#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

int main()
{
	int fd = open("sb.txt", O_RDWR, 0644);
	void * ptr;
	if (fd < 0){
		perror(" ");
		return -1;
	}
	ptr = mmap(NULL,1024,PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
	if (!ptr){
		perror(" ");
		return -1;
	}
	//memcpy(ptr,"a\n",2);
	printf("%s", ptr);
	munmap(ptr,1024);
	close(fd);
	return 0;
}
