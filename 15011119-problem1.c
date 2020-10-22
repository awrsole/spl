#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	//define variable
	pid_t pid;
	int a;

	if ((pid = fork()) < 0)//make child process and processing error
	{
		perror("error");
	}else if(pid ==0) {//child process do
		printf("child PID is %d, Parent PID is %d\n", getpid(), getppid());
	//print child process pid, ppid	
	}
	else{
		sleep(3);//parent process wait child process 
		printf("Parent PID is %d\n", getpid());//parent process print pid
	}
	exit(0);// end
}
