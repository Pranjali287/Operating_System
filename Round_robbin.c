#include<stdio.h>
int main()
{
int n;
printf("\n Enter the number of processes:");
scanf("%d",&n);
int bt[n],wt[n],tat[n];
printf("\n enter the burst time of each processes");
for(int i=1;i<=n;i++)
{
	scanf("\n %d",&bt[i]);
}
int qt,time=0;
printf("enter the time quantum: ");
scanf("\n %d",&qt);
int rem_bt[n];
for(int i=1;i<=n;i++)
{
rem_bt[i]=bt[i];
}
while(1){
 	int done=1;
	for(int i=1;i<=n;i++){
		if(rem_bt[i]>0)
		{
		done=0;
		if(rem_bt[i]>qt){
			time=time+qt;
			rem_bt[i]-=qt;
		}
		else{
			time=time+rem_bt[i];
			wt[i]=time-bt[i];
			rem_bt[i]=0;
		}
		}
	}
	if(done==1)
	{
		break;
	}
}
for (int i=1;i<=n;i++)
{
	tat[i]=wt[i]+bt[i];
}
for (int i=1;i<=n;i++)
{
printf("the process %d	%d  %d  %d\n",i,bt[i],wt[i],tat[i]);
}
}
