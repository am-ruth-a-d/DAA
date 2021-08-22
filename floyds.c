#include <stdio.h>
#include<time.h>
int min(int a,int b);
void floyd(int n,int w[10][10],int d[10][10]);
int main()
{   int w[10][10],d[10][10],n,i,j,k;
    char choice;
    double clk;
    clock_t starttime,endtime;
    srand(time(0));
    printf("WELCOME TO FLORIDA STATE FIRE DEPARTMENT\n\n");
    printf("Would you like to make an enquiry? y/n\n");
    scanf("%c",&choice);
    if(choice=='n'||choice=='N')
    return 0;
    printf("Enter the no. of residential :\n");
    scanf("%d",&n);
    printf("Enter the distance between the residential layouts and the fire station :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&w[i][j]);
    starttime=clock();
    floyd( n,w,d);
    endtime=clock();
    printf("The shortest path and min distance is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",d[i][j]);
        printf("\n");
    }
     clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
     printf("\nThe run time is %f\n",clk);
    return 0;  }
void floyd(int n,int w[10][10],int d[10][10])
{
    int i,k,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            d[i][j]=w[i][j];
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
 }   }   }   }
int min(int a,int b)
{ if(a<b)
        return a;
    else
        return b;  }
