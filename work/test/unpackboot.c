#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE (10*1024*1024)
#define BOOT_MAGIC "ANDROID!"
#define BOOT_MAGIC_SIZE 8
#define BOOT_NAME_SIZE 16
#define BOOT_ARGS_SIZE 512

struct boot_img_hdr
{
    unsigned char magic[BOOT_MAGIC_SIZE];
    unsigned kernel_size;  
    unsigned kernel_addr;  
    unsigned ramdisk_size; 
    unsigned ramdisk_addr; 
    unsigned second_size;  
    unsigned second_addr;  
    unsigned tags_addr;    
    unsigned page_size;    
    unsigned unused[2];    
    unsigned char name[BOOT_NAME_SIZE];
    unsigned char cmdline[BOOT_ARGS_SIZE];
    unsigned id[8]; 
}hdr;

int main(int argc, char **argv)
{
	int fd, kfd, rfd;
	int seek, count;
	char *data = malloc(BUFSIZE);
	if (argc != 2){
		fprintf(stderr, "%s /dir/boot.img\n", argv[0]);
		return -1;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0){
		fprintf(stderr, "open %s %s", argv[1], strerror(errno));
		return -1;
	}

	kfd = open("lokernel", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (kfd < 0){
		close(fd);
		fprintf(stderr, "create kernel file:%s", strerror(errno));
		return -1;
	}
	rfd = open("loramdisk", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (rfd < 0){
		fprintf(stderr, "create ramdisk file:%s", strerror(errno));
		close(fd);
		close(kfd);
		return -1;
	}
	read(fd, &hdr, sizeof(hdr));

	seek = ((sizeof(hdr) + 2047) / 2048) * 2048;
	lseek(fd, seek, SEEK_SET);
	count = read(fd, data, hdr.kernel_size);
	if (count < hdr.kernel_size) {
		fprintf(stderr, "kernel size error\n");
		close(fd);
		close(kfd);
		close(rfd);
		return -1;
	}
	write(kfd, data, count);

	seek += ((hdr.kernel_size + 2047) / 2048) * 2048;
	lseek(fd, seek, SEEK_SET);
	count = read(fd, data, hdr.ramdisk_size);
	if (count < hdr.ramdisk_size ) {
		fprintf(stderr, "ramdisk size error\n");
		close(fd);
		close(kfd);
		close(rfd);
		return -1;
	}
	write(rfd, data, count);
	
	close(fd);
	close(kfd);
	close(rfd);
	free(data);
	
	fprintf(stdout, "unpack boot.img success!\n");
	fprintf(stdout, "kernel size is %d, ramdisk size is %d.\n", hdr.kernel_size, hdr.ramdisk_size);
	return 0;
}
