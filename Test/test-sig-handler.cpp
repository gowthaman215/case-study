// CPP program to illustrate
// User-defined Signal Handler
#include<stdio.h>
#include<signal.h>
#include <stdlib.h>

// Handler for SIGINT, caused by
// Ctrl-C at keyboard
void handle_sigint(int sig)
{
	char log[100];
	char command[200];
	
	sprintf(log,"Caught signal id %d",sig);
	sprintf(command, "echo \"%s\" >> file.txt",log);
	system(command);
	exit(1);
}

int main()
{
 signal(SIGHUP, handle_sigint);
 signal(SIGINT, handle_sigint);
 signal(SIGQUIT, handle_sigint);
 signal(SIGILL, handle_sigint);
 signal(SIGTRAP, handle_sigint);
 signal(SIGABRT, handle_sigint);

 while (1) ;
 return 0;
}

