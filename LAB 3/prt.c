#include <stdio.h>
#include <string.h>
void main()
{
	float awt=0, att=0;
	int p[20],prt[20],bt[20],wt[20],tt[20],n,i,j;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the burst time of processes and priority(High priority number = Highest priority)\n");
	for(i=0;i<n;i++)
	{
		printf("p%d: ",i+1);
		p[i]=i+1;
		scanf("%d",&bt[i]);
		printf("\t");
		printf("Priority: ");
		scanf("%d",&prt[i]);
	}
	
	int temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(prt[i]<prt[j])
			{
				temp= bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				
				temp=prt[i];
				prt[i]=prt[j];
				prt[j]=temp;
			}
		}
	
	}
	
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		awt=awt+wt[i];
	}
	
	for(i=0;i<n;i++)
	{
		tt[i]=bt[i]+wt[i];
		att=att+tt[i];
	}
	printf("Average tt = %f \n",att/n);
	printf("Average wt = %f\n",awt/n);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("|\tP%d\t|",p[i]);
	}
	printf("\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",wt[i]);
	}
}	
