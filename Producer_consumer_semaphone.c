#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=10;
void  producer();
void consumer();
int main()
{
	printf("Press 1 for Producer\n");
	printf("Press 2 for Consumer\n");
	printf("Press 3 for exit\n");
	while(1){
		again: printf("Enter your choice\n");
		int n;
		scanf("%d",&n);
		switch(n){
			case 1:
				if((mutex==1) && (empty!=0)){
					producer();
					printf("Item Produced\n");
				}
				else{
					printf("The Buffer is Full\n");
				}
				break;
			case 2:
				if((mutex==1) &&  (full!=0)){
					consumer();
					printf("Item Consumed\n");
				}
				else{
					printf("The Buffer is empty\n");
				}
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Invalid Input\n");
				goto again;
			}
	}
}
void producer()
{
	--mutex;
	++full;
	--empty;
	++mutex;
}
void consumer()
{
	--mutex;
	--full;
	++empty;
	++mutex;
}
