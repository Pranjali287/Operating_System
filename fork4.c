#include<stdio.h>
#include<unistd.h>
int main()
{
 printf("Before execvp()\n");
 int status=execvp("ls",("ls","-1",NULL));
    if (status==-1)
{
          printf("Terminated incorrectly\n");
 }
    printf("This will not be printed");
}
