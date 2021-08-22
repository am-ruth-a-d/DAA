#include <stdio.h>
#include<time.h>
int main()
{
    char choice; 
    int a[10][10],n,i,j,k;
    double clk;
    clock_t starttime,endtime;
    srand(time(0));
    printf("WELCOME MEDICAL REPRESENTATIVE\n\n");
    printf("Would you like to make an enquiry? y/n\n");
    scanf("%c",&choice);
    if(choice=='n'||choice=='N')
    return 0;
    printf("Enter the number of cities n:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    starttime=clock();
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
            }
        }
    }
    endtime=clock();
    printf("The transitive closure is:\n");
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
     }
     clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
     printf("%f",clk);
}
