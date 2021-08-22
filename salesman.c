#include<stdio.h>
#include<time.h>

int c[1000][10],count=1,cost[10][10];
void copy(int a[],int b[])
{
	int i;
	for(i=1;i<9;i++)
		a[i]=b[i];

}
int comb_gen(int l, int n, int a[])
{
	int x[10],i,j;
	if(l>n)
		copy(c[count++],a);
	else
		for(i=2;i<=l;i++)
		{
			copy(x,a);
			for(j=l;j>i;j--)
				x[j]=x[j-1];
			x[j]=l;
			comb_gen(l+1,n,x);
		}

}
int ex_search(int n)
{
	int f, i, j, min_cost=999, sum, min_path, x[10],temp[10]={1,1};
	comb_gen(2,n,temp);
	f=count-1;
	printf("\n Number of ways that can be followed are = %d\n",f);
	for(i=1;i<=f;i++)
	{
		sum=0;
		copy(x,c[i]);
		for(j=1;j<n;j++)
			sum=sum+cost[x[j]][x[j+1]];
		sum+=cost[x[n]][x[1]];
		
		if(sum <min_cost)
		{
			min_cost=sum;
			min_path=i;
		}
	}
	printf("Best optimal order to follows is \n");
	for(i=1;i<=n;i++)
		printf("%d -> ",c[min_path][i]);
	printf("%d := %d\n",c[min_path][1],min_cost);
	return(min_cost);
}

void main()
{
	double clk;
	clock_t starttime,endtime;
	srand(time(0));
	char choice;
	int n,i,j,err;
	float fsa,fs;
	printf("WELCOME TO COX AND KINGS\n\n");
	printf("Would you like to make an enquiry? y/n\n");
	scanf("%c",&choice);
	if(choice=='n'||choice=='N')
	return 0;
	printf("Enter the no. of Destinations :");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);

      starttime=clock();
	fs = ex_search(n);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
      printf("\nThe run time is %f\n",clk);
}
























