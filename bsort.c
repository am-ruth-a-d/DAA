#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
char choice;
int n=100,i;
double clk;
clock_t starttime,endtime;
srand(time(0));
printf("WELCOME TO CINEPLIX\n\n");
printf("Would you like to make an enquiry? y/n\n");
scanf("%c",&choice);
if(choice=='n'||choice=='N')
return 0;
printf("Enter the number of seats\n");
scanf("%d",&n);
int A[n];
printf("All available seats are\n");
for(i=0;i<n;i++)
{
A[i]=rand()%1000 +1000;
printf("%d\t",A[i]);
}
 printf("\nSeats available in ascending order is\n");
 printf("\n");
 bubblesort(A,n);
 for(i=0;i<n;i++)
{
printf("%d\t",A[i]);
}
 starttime=clock();
 bubblesort(A,n);
 endtime=clock();
 clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 printf("\nThe run time is %f\n",clk);
 }
 
void bubblesort(int A[],int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
 	for(j=0;j<n-1-i;j++)
 		if(A[j+1]<A[j])
 		{
 		  temp=A[j];
 		  A[j]=A[j+1];
 		  A[j+1]=temp;
 		 } 
 }
