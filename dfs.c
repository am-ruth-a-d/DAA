#include<stdio.h>
#include<time.h>
int a[10][10];
int count=-1,n;
int reach[50],pos[50];

void read_matrix()
{
	int i,j;
	printf("Enter the adjacency matrix(enter 0/1)\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i!=j)
	{
		printf("%d,%d:",i,j);
		scanf("%d",&a[i][j]);
	}
}

void dfs(int v)
{
	int u;
	reach[++count]=v;
	u=adjacent(v);
	while(u)
	{
		if(checkreach(u)==0)
		dfs(u);
		u=adjacent(v);
	}
}

int adjacent(int i)
{
	int j;
	for(j=pos[i]+1;j<=n;j++)
	if(a[i][j]==1)
	{
		pos[i]=j;
		return j;
	}
	pos[i]=n+1;
	return 0;
}

int checkreach(int u)
{
	int i;
	for(i=1;i<=count;i++)
	if(reach[i]==u)
		return 1;
	return 0;
}

void main()
{	char choice;
	int v,i;
	double clk;
	clock_t starttime,endtime;
	srand(time(0));
	printf("\nHELLO FROM DIGITAL MAPS\n\n");
	printf("Would you like too see the connectivity between cities? Y/N:\n");
	scanf("%c",&choice);
	if(choice=='n'||choice=='N')
	return 0;
	printf("Enter the number of islands: \n");
	scanf("%d",&n);
	for(i=1;i<=count;i++)
	pos[i]=0;
	printf("Enter the matrix representation of islands reachable:\n");
	read_matrix();
	printf("Enter the starting island: \n");
	scanf("%d",&v);
	starttime=clock();
	dfs(v);
	endtime=clock();
 	clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	printf("Islands reachable from the given island are...\n");
	for(i=0;i<count;i++)
	printf("%d\t",reach[i]);
 	printf("\nThe run time is %f\n",clk);
 }























