#include <stdio.h>
#define BB 1
int main()
{
#if AA
	printf("AA=%d\n",AA);
#elif BB
	printf("BB=%d\n",BB);
#else
	printf("CC\n");
#endif
	return 0;
}
