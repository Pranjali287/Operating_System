#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
printf("Befor fork()\n");
pid_t p=fork();
printf("my id is:%d\n",getpid());
return(0);
}
