#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sighandler(int signo, siginfo_t *si){
	if(si->si_code ==SI_QUEUE)
	{
	printf("User RTS signal %d\n", si->si_pid);//sender pid
	printf("SIG Number %d\n", si->si_signo);//SIG number
	printf("SIG vaule %d\n", si->si_value.sival_int);//receive value
	getchar();
	}
	else{
	printf("no RTS\n");}
}//signal handler

int main ()
{

	struct sigaction sigact;
	printf("my pid %d\n", getpid());//receiver's pid
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_restorer = NULL;
	sigact.sa_sigaction = sighandler;//setup for sigaction

	if(sigaction(SIGTSTP, &sigact, 0 ) == 1)//if SIGTSTP go handler
	{
		printf("error");
		exit(0);
	}

	while(1)
	{
	sleep(1);
	}
}
