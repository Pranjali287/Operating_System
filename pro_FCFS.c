#include<stdio.h>
int main()
{
int n;
printf("\n Enter the number of processes:");
scanf("%d",&n);
int bt[n],wt[n],tat[n];
printf("\n enter teh burst time of each processes");
for(int i=1;i<=n;i++)
{
	scanf("\n %d",&bt[i]);
}
wt[1]=0;
for(int i=2;i<=n;i++)
{
	wt[i]=wt[i-1]+bt[i-1];
}
for(int i=1;i<=n;i++)
{
	tat[i]=bt[i]+wt[i];
}
for(int i=1;i<=n;i++)
{
	printf("\nprocess %d	%d	%d	%d\n",i,bt[i],wt[i],tat[i]);
}
}
