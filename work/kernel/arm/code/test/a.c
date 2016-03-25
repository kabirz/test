#include <stdio.h>
#define copy_to_a(x,y) x=y
int main()
{
	int code ;
	copy_to_a(code,100);
	printf("code=%d\n",code);
	return 0;
}
