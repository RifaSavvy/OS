#include<sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<fcntl.h>
void main()
{
	int fd,fd2;
	char wbuf[120];
	char rbuf[120];
	fd=open("RIFA.txt",O_RDWR);
	printf("Enter the text to be Written\n");
	scanf("%s",wbuf);
	write(fd,wbuf,strlen(wbuf));
	close(fd);
	fd2=open("RIFA.txt",O_RDWR);
	printf("\nThe contents are :\n");
	read(fd2,rbuf,100);
	printf("%s\n",rbuf);
	close (fd2);
	}
	
