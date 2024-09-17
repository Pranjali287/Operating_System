#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
printf("Befor fork\n");
pid_t p=fork();
if(p<0)
{
printf("fork failed\n");
}
else if(p==0)
{
printf("my id is:%d\n",getpid());
printf("my parent id is:%d\n",getppid());
}
else
{
printf("my id is:%d\n",getpid());
printf("my child id is:%d\n",p);
}
printf("Done\n");
return 0;
}
