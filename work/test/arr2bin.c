#include <stdio.h>
#include <unistd.h>
char array[]={
#include "a.i"
};
int main()
{
	unsigned int i;
	for(i=0;i<sizeof(array);i+=100)
		write(1,&array[i],100);
	if(i-100<sizeof(array))
		for(i;i<sizeof(array);i++)
			write(1,&array[i],1);
	return 0;
}
