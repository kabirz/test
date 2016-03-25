#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char * argv[]){

	struct timeval tv;                //(1)
	while(1){
		gettimeofday(&tv, NULL);      //(2)
		printf("time %u:%u\n", tv.tv_sec, tv.tv_usec);
		sleep(2);
	}
	return 0;

}


