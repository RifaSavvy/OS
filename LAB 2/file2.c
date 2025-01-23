#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main()
{
	int status,pid,child_pid;
	pid=fork();
	if (pid==-1){
		printf("child process is not created");
		exit(0);}
	else if(pid==0){
		printf("child process id=%d\n",getpid());
		execl("/bin/date","date",NULL);}
	else{
		child_pid=wait(&status);
		printf("parent process id=%d\n",getpid());
		printf("child process created");
		}
}
