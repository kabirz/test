#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void int_hander(int s)
{
	printf("Catch a signal sigint\n");
}

int main(void)
{
	int i;
	struct sigaction act, oact;
	act. sa_handler = int_hander;
	sigemptyset(&act. sa_mask); //��մ��źż�
	act. sa_flags = 0;
	sigaction(SIGINT, &act, NULL/*&oact*/);
	//signal(SIGINT, SIG_IGN);
	while(1){
		for(i=0; i<5; i++){
			write(1, ".", 1);
			sleep(1);
		}
		write(1, "\n", 1);
	}
	//sigaction(SIGINT, &oact, NULL); 
	return 0;
}
