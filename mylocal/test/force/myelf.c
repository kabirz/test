#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define FALSE 0
#define TURE 1
#define MAX_SIZE 52

typedef short int     Elf32_Half;
typedef int         Elf32_Word;
typedef Elf32_Word     Elf32_Addr;
typedef Elf32_Word     Elf32_Off;
/*Elf头部文件部分重要数据*/
typedef struct{
	Elf32_Half e_type;
	Elf32_Half e_machine;
	Elf32_Word e_version;
	Elf32_Addr e_entry; //程序入口的虚拟地址，如果目标文件没有程序入口，为0 
	Elf32_Off e_phoff; //程序头部表格的偏移量（按字节），如果文件中没有，为0
	Elf32_Off e_shoff; //节区头部表格的偏移量（按字节），如果文件中没有，为0    
	Elf32_Word e_flags; //
	Elf32_Half e_ehsize; //ELF头部的大小
	Elf32_Half e_phentsize; //程序头部表格的表项大小。
	Elf32_Half e_phnum; //程序头部表格的表项数目。
	Elf32_Half e_shentsize; //节区头部表格的表项大小。
	Elf32_Half e_shnum; //节区头部表格的表项数目。
	Elf32_Half e_shstrndx;
}Elf_lan;
static Elf_lan lan_elf;
int OpenElf(char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);
	if(fd == -1){
		printf("Open %s Error!\n", filename);
		return FALSE; 
	}
	return fd; 
}
//读取Elf头部表函数 :int ReadElf(int fd);

int ReadElf(int fd)
{
	char str[MAX_SIZE];
	int num;
	memset(str, 0, MAX_SIZE);
	if((num = read(fd, str, 52)) != 52){
		perror("File NO ELF!\n");
		return FALSE; 
	}
	if((str[0] == 0x7f) && (str[1] == 'E') && (str[2] == 'L') && (str[3] == 'F')){
		printf("This is ELF file.\n");
		printf("文件类别： "); 
		switch(str[4]){
			case 0:
				printf("非法目标文件\n");
				break;
			case 1:
				printf("32位目标文件\n");
				break;
			case 2:
				printf("64位目标文件\n");
				break;
			default:
				break;             
		}
		printf("编码格式: ");
		switch(str[5]){
			case 0:
				printf("非法编码格式\n");
				break;
			case 1:
				printf("小端编码格式\n");
				break;
			case 2:
				printf("大端编码格式\n");    
				break;
			default:
				break;    
		}
		printf("文件版本： ");
		if(str[6] == 1){
			printf("当前版本\n");
		}else{
			printf("NULL\n");
		}
		printf("目标文件类型： ");
		lan_elf.e_type = *((Elf32_Half *)&str[16]);
		printf("e_type = %d\t", lan_elf.e_type); 
		switch(lan_elf.e_type){
			case 0:
				printf("未知文件类型\n");
				break;
			case 1:
				printf("可重定位文件类型\n");
				break;
			case 2:
				printf("可执行文件\n");
				break;
			case 3:
				printf("动态链接库文件\n");
				break;
			case 4:
				printf("CORE文件\n");
				break;
			default:
				break;                        
		}
		printf("体系结构为：");
		lan_elf.e_machine = *((Elf32_Half *)&str[18]);
		printf("e_machine = %d\n", lan_elf.e_machine);
		switch(lan_elf.e_machine){
			case 0:
				printf("未知体系结构");
				break;
			case 3:
				printf("Intel 8086"); 
		}
		printf("版本信息： ");
		lan_elf.e_version = *((Elf32_Word *)&str[20]);
		if(lan_elf.e_version == 1){
			printf("当前版本\n");
		}else{
			printf("NULL\n");
		}
		printf("程序入口的虚拟地址：");
		lan_elf.e_entry = *((Elf32_Word *)&str[24]);
		printf("0x%x\n", lan_elf.e_entry);

		printf("程序头部表格的偏移量（按字节）： ");
		lan_elf.e_phoff = *((Elf32_Off *)&str[28]);
		printf("0x%x, %d\n", lan_elf.e_phoff, lan_elf.e_phoff);

		printf("节区头部表格的偏移量（按字节）： ");
		lan_elf.e_shoff = *((Elf32_Off *)&str[32]);
		printf("0x%x, %d\n", lan_elf.e_shoff, lan_elf.e_shoff);

		printf("处理器标志位： ");
		lan_elf.e_flags = *((Elf32_Off *)&str[36]);
		printf("%d\n", lan_elf.e_flags);

		printf("ELF头文件大小： ");
		lan_elf.e_ehsize = *((Elf32_Half *)&str[40]);
		printf("0x%x, %d\n", lan_elf.e_ehsize, lan_elf.e_ehsize);

		printf("程序头部表大小： ");
		lan_elf.e_phentsize = *((Elf32_Half *)&str[42]);
		printf("0x%x, %d\n", lan_elf.e_phentsize, lan_elf.e_phentsize);

		printf("程序头部表的数目：");
		lan_elf.e_phnum = *((Elf32_Half *)&str[44]);
		printf("0x%x, %d\n", lan_elf.e_phnum, lan_elf.e_phnum);

		printf("节区头部表大小： ");
		lan_elf.e_shentsize = *((Elf32_Half *)&str[46]);
		printf("0x%x, %d\n", lan_elf.e_shentsize, lan_elf.e_shentsize);

		printf("节区头部表数目： ");
		lan_elf.e_shnum = *((Elf32_Half *)&str[48]);
		printf("0x%x, %d\n", lan_elf.e_shnum, lan_elf.e_shnum);

		printf("节头表与节名字相对应的表项的索引： ");
		lan_elf.e_shstrndx = *((Elf32_Half *)&str[50]);
		printf("0x%x, %d\n", lan_elf.e_shstrndx, lan_elf.e_shstrndx);
		return TURE; 
	}else{
		perror("File NO ELF!\n");
		return FALSE; 
	} 
}

int main(int argc, char *argv[])
{
	int boolen;
	if(argc == 2){
		boolen = OpenElf(argv[1]);
		if(boolen == FALSE){
			return -1; 
		}
		ReadElf(boolen); 
	}

	return 0; 
}
