#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	double clk;
	clock_t starttime,endtime;
	srand(time(0));
char choice;
int n=100,key,i;
printf("WELCOME TO MEDPLUS\n\n");
printf("Would you like to make an enquiry? y/n\n");
scanf("%c",&choice);
if(choice=='n'||choice=='N')
return 0;
printf("Enter the total number of medicines\n");
scanf("%d",&n);
int A[n];
 starttime=clock();
printf("Available medicines are:\n");
for(i=0;i<n;i++)
{
A[i]=rand()%1000 +1000;
printf("%d\t",A[i]);
}
printf("\nEnter the medicine ID to be searched \n");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(A[i]==key)
 {printf("%d FOUND AT POSITION %d\n",key,i+1);
 endtime=clock();
 clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 printf("\nThe run time is %f\n",clk);
 return 0;
 }
 endtime=clock();
 clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
} 
 printf("Medicine not available\n");
 printf("\nThe run time is %f\n",clk);
 }
 

