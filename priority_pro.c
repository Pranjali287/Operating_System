#include<stdio.h>
int main()
{
int n;
printf("\n enter the number of process \n");
scanf("%d",&n);
int bt[n],tat[n],wt[n],p[n],pr[n];
printf("\n enter the burst time of the process");
for(int i=1;i<=n;i++)
{
	scanf("%d \n",&pr[i]);
}
for(int i=1;i<=n;i++)
{
	scanf("\n %d",&bt[i]);
	p[i]=i;
}
int temp;
for(int i=1;i<=n;i++)
{
	for(int j=i+1;j<=n;j++)
	{
		if(pr[i]>pr[j])
		{
		temp=pr[i];
		pr[i]=pr[j];
		pr[j]=temp;
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
		}
	}
}
wt[1]=0;
for(int i=2;i<=n;i++)
{
	wt[i]=wt[i-1]+bt[i-1];
}
for(int i =1;i<=n;i++)
{
	tat[i]=wt[i]+bt[i];
}
for(int i=1;i<=n;i++)
{
	printf(" %d process:%d	%d	%d	%d\n",pr[i],p[i],bt[i],wt[i],tat[i]);
}
}
