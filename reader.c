#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define FIFO_NAME "myfifo"
#define BUFFER_SIZE 100
int main()
{
	int fd;
	char buffer[BUFFER_SIZE];
	fd=open(FIFO_NAME,O_RDONLY);
	if(fd==-1)
	{
	perror("Error opening the FIFO for reading");
	exit(0);
	}
	while(1)
	{
		ssize_t bytes=read(fd,buffer,BUFFER_SIZE);// IN PLACE OF BUFFER_SIZE you can give any value that are the storage size of buffer
		if(bytes>0)
		{
			printf("Recevied: %s",buffer);
		}
		else
		{
			break;
		}
	}
	close(fd);
}
