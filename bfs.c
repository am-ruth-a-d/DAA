#include<stdio.h>
#include<time.h>


void bfs(int a[10][10],int n, int source)
{
       int s[10],q[10],f=0,r=-1,t,v;
	for(v=0;v<n;v++)
	{
		s[v]=0;
	}
	q[++r]= source;
	s[source]=1;
	while(f<=r)
	{
		t=q[f++];
		printf("t=%d\n",t);
		for(v=0;v<n;v++)
		if(a[t][v]==1 && s[v]==0)
		{
			q[++r]=v;
			printf("The city reachable from %d is %d\n",t,v);
			printf("f=%d r=%d\n",f,r);
			s[v]=1;
		}
	}
	
	for(v=0;v<n;v++)
	{
	printf("s[%d]=%d\n",v,s[v]);
	printf("q[%d]=%d\n",v,q[v]);
	}
}

void main()
{
	int a[10][10],n,s;
	int i,j;
	char choice;
	double clk;
	clock_t starttime,endtime;
	printf("\n\nHELLO FROM DIGITAL MAPS\n\n");
	printf("Would you like too see the connectivity between cities? Y/N:\n");
	scanf("%c",&choice);
	if(choice=='n'||choice=='N')
	return 0;
	printf("Enter the no. of cities:\n");
	scanf("%d",&n);
	printf("Enter the matrix representation of cities reachable:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("Enter the starting city\n");
	scanf("%d",&s);
	starttime= clock();
	bfs(a,n,s);
	endtime= clock();
	clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	printf("The run time is: %f\n",clk);
}
