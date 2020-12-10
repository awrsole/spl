#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
int main (int argc, char **argv){
	union sigval sv;
	sv.sival_int = atoi(argv[2]);
	sigqueue(atoi(argv[1]),SIGTSTP, sv);
}
//agrv[1] = receiver's pid agrv[2] = message for receiver
