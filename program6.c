/*6. Develop a C program to simulate the following contiguous memory allocation Techniques:
a) Worst fit b) Best fit c) First fit.*/
#include <stdio.h>
void firstfit(int [], int ,int );
void worstfit(int [], int ,int );
void bestfit(int [], int ,int );
int allocation=-1;
int main() {
    int m, n;
    // Input number of memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
	int blockSize[m];
    // Input size of each memory block
    printf("Enter size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input size of each process
    printf("Enter size of process:\n");
        scanf("%d", &n);

    // First Fit Allocation
    firstfit(blockSize, m, n);
	// Worst Fit Allocation
    worstfit(blockSize, m, n);
    // Best Fit Allocation
    bestfit(blockSize, m, n);
    return 0;
}
void firstfit(int blockSize[], int m,int n)
{
	for (int i = 0; i < m; i++) {
            if (blockSize[i] >= n) {
                allocation= i; 
                break;
        }
    }
    // Output allocation results
    printf("\nFirst Fit Allocation:\n");
    printf("Process allocated to Block %d of size %d\n", allocation,blockSize[allocation]);	
}
void worstfit(int blockSize[], int m,int n)
{
	int max=blockSize[0];
	for(int i=1;i<m;i++)
	{
		if(max<blockSize[i])
		{
			max=blockSize[i];
			allocation=i;
		}
	}
    // Output allocation results
    printf("\nWorst Fit Allocation:\n");
    printf("Process allocated to Block %d of size %d\n", allocation,blockSize[allocation]);	
}
void bestfit(int blockSize[], int m,int n)
{
	for(int i=0;i<m-1;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(blockSize[i]>blockSize[j])
			{
				int c=blockSize[i];
				blockSize[i]=blockSize[j];
				blockSize[j]=c;
				
			}
		}
	}
	for (int i = 0; i < m; i++) {
            if (blockSize[i] >= n) {
                allocation= i; 
                break;
        }
    }
    // Output allocation results
    printf("\nBest Fit Allocation:\n");
    printf("Process allocated to Block %d of size %d\n", allocation,blockSize[allocation]);	
}
