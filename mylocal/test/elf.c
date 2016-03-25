#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef __u16 Elf32_Half;
typedef __u32 Elf32_Word;
typedef __u32 Elf32_Addr;
typedef __u32 Elf32_Off;
struct elf32_hdr{
 unsigned char e_ident[16];
 Elf32_Half e_type;
 Elf32_Half e_machine;
 Elf32_Word e_version;
 Elf32_Addr e_entry;
 Elf32_Off e_phoff;
 Elf32_Off e_shoff;
 Elf32_Word e_flags;
 Elf32_Half e_ehsize;
 Elf32_Half e_phentsize;
 Elf32_Half e_phnum;
 Elf32_Half e_shentsize;
 Elf32_Half e_shnum;
 Elf32_Half e_shstrndx;
} ;

int main(int argc,char**argv)
{
	struct elf32_hdr test;
	int fd;
	int i;
	if(argc == 2) {
		fd = open(argv[1],O_RDONLY);
		if(fd<0) return -1;
		read(fd,(void*)&test,sizeof(struct elf32_hdr));
		printf("type=%d,machine=%d,e_version=%d,entry=%d,phoff=%d,shoff=%d,flags=%d,ehsize=%d\n,\
phentsize=%d,phnum=%d,shentsize=%d,shnum=%d,shstrndx=%d\n",
				test.e_type,test.e_machine,test.e_version,test.e_entry,test.e_phoff,test.e_shoff,
				test.e_flags,test.e_ehsize,test.e_phentsize,test.e_phnum,test.e_shentsize,test.e_phnum,test.e_shentsize,
				test.e_shnum,test.e_shstrndx);
		for(i=0;i<16;i++)
			printf("%c ",test.e_ident[i]);
		printf("\n");
		return 0;
	}
	else 
		return -1;
}
