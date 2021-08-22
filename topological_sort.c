#include<stdio.h>
#include<time.h>

int main()
{

double clk;
clock_t starttime,endtime;

int i,j,k,n,a[100][100],indeg[100],flag[100],count=0; 

printf("Enter the no of vertices:\n");

scanf("%d",&n);

printf("Enter the adjacency matrix:\n");

for(i=0;i<n;i++)

for(j=0;j<n;j++)

scanf("%d",&a[i][j]);



 starttime=clock();

for(i=0;i<n;i++){

        indeg[i]=0;

        flag[i]=0;   } 

    for(i=0;i<n;i++)

        for(j=0;j<n;j++)

            indeg[i]=indeg[i]+a[j][i]; 

    printf("\nThe topological order is:"); 

    while(count<n){

        for(k=0;k<n;k++){

            if((indeg[k]==0) && (flag[k]==0)){

                printf("%d ",(k+1));

                flag [k]=1;

            }

            for(i=0;i<n;i++){

                if(a[i][k]==1)

                    indeg[k]--;

            }    }

     count++;

    }   
    
    endtime=clock();
 
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 
    printf("\nThe run time is %f\n",clk);
 
 
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
