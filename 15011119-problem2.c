#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>

void handler(int signo){
	char *s;
	s= strsignal(signo);
	printf("Received signal : %s\n", s);
}
void myalarm(){
	printf( "Waiting for signal to be received! Count : %d\n",);//alarm
}

int main(){
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_flags =0;
	act.sa_handler = handler;
	if(sigaction(SIGTSTP, &act, (struct sigaction *)NULL)<0{
			perror("sigaction");
			exit(1);

	}

	if(sigaction(SIGINT, &act, (struct sigaction *)NULL)<0{
                        perror("sigaction");
                        exit(1);
			}
	while(1){
	alarm(1);
	signal(SIGALRM, myalarm);
	fprintf(stderr, "Waiting for signal to be received! Count : %d\n",);//alarm
	}
	
	
	return 0;

	}
