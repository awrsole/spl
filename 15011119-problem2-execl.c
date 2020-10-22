#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	if((pid = fork()) <0)//create child process
	{
		perror("fork error\n");//fork error process
	}else if(pid == 0)//child process execute
	{
	execl("/bin/ls", "ls", (char *)0);//execute execl operation 
	perror("execl() error\n");//execl error process
	}
	else//parent process execute
	{
		wait((int *)0);//parent process wait child process
		printf("execl() function execution\n");
	}
	return 0; //end
}	
