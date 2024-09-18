#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{
pid_t p=fork();
if(p<0)
{
printf("fork failed \n");
}
else if(p==0)
{
printf("the id of the child is %d \n",getpid());
printf("the parents id is %d \n",getppid());
}
else
{
printf("the parent id id %d \n",getpid());
wait(NULL);
printf("the id of child is %d \n",p);
}
}
