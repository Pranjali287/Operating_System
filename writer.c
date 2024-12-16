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
	//Opening the FIFO for writing
	fd=open(FIFO_NAME,O_WRONLY);
	if(fd==-1)
	{
		perror("Error in opening the FIFO for writing\n");
		exit(0);
	}
	//Writing the message to the FIFO
	snprintf(buffer,BUFFER_SIZE,"Message from the  writer\n");
	write(fd,buffer,strlen(buffer)+1);
	
	close(fd);
}
