#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
printf("Begin\n");
pid_t p=fork();
if(p<0)
{
printf("fork failed\n");
}
else if(p==0)
{
printf("child process\n");
int status=execvp("ls",("ls","-1",NULL));
if(status==-1)
{
printf("Terminated\n");
}
}
else 
{
printf("parent process\n");
printf("Done\n");
}
}
