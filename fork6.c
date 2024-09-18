#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
printf("Befor execvp()\n");
pid_t p=fork();
if(p==0)
{
int status=execvp("ls",("ls","-l",NULL));
if(status==-1)
{
printf("Terminated\n");
exit(1);
}
}
else
{
printf("parent process\n");
wait(NULL);
printf("Done\n");
}
}
