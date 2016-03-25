#include <linux/elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

static const char *file_type[]={"非法目标文件\n","32位目标文件\n","64位目标文件\n",NULL};
static const char *code_type[]={"非法编码格式\n","小端编码格式\n","大端编码格式\n",NULL};
static const char *e_type[]={"未知文件类型\n","可重定位文件类型\n","可执行文件\n","动态链接库文件\n","CORE文件\n",NULL};
static Elf32_Ehdr lan_elf;
int main(int argc, char *argv[])
{
	char *str = (char *)&lan_elf;
	int fd;
	if(argc < 2){
		perror("Uage:xx file\n");
		return -1;
	}
	fd = open(argv[1],O_RDONLY);
	read(fd, &lan_elf, sizeof(lan_elf));
	if((str[0] == 0x7f) && (str[1] == 'E') && (str[2] == 'L') && (str[3] == 'F')){
		printf("文件类别：%s",file_type[str[4]]); 
		printf("编码格式: %s",code_type[str[5]]);
		printf("目标文件类型：%s",e_type[lan_elf.e_type]);
		printf("体系结构为：%d\n",lan_elf.e_machine);
		printf("程序入口的虚拟地址：0x%x\n", lan_elf.e_entry);
		printf("程序头部表格的偏移量（按字节）：0x%x, %d\n", lan_elf.e_phoff, lan_elf.e_phoff);
		printf("节区头部表格的偏移量（按字节）：0x%x, %d\n", lan_elf.e_shoff, lan_elf.e_shoff);
		printf("处理器标志位：%d\n", lan_elf.e_flags);
		printf("ELF头文件大小：0x%x, %d\n", lan_elf.e_ehsize, lan_elf.e_ehsize);
		printf("程序头部表大小：0x%x, %d\n", lan_elf.e_phentsize, lan_elf.e_phentsize);
		printf("程序头部表的数目：0x%x, %d\n", lan_elf.e_phnum, lan_elf.e_phnum);
		printf("节区头部表大小：0x%x, %d\n", lan_elf.e_shentsize, lan_elf.e_shentsize);
		printf("节区头部表数目：0x%x, %d\n", lan_elf.e_shnum, lan_elf.e_shnum);
		printf("节头表与节名字相对应的表项的索引：0x%x, %d\n", lan_elf.e_shstrndx, lan_elf.e_shstrndx);
	}else{
		perror("File NO ELF!\n");
		return -1; 
	} 
		return 0; 
}
