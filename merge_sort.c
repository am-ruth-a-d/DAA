#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int  A[100000];
void merge(int,int,int);
int main()
{
char choice;
int n=100,i;
double clk;
clock_t starttime,endtime;
srand(time(0));
printf("WELCOME TO DELOIT SOFTWARE COMPANY\n\n");
printf("Would you like to make an enquiry? y/n\n");
scanf("%c",&choice);
if(choice=='n'||choice=='N')
	return 0;
printf("Enter the number of employees\n");
scanf("%d",&n);
printf("All available ID numbers are\n");
for(i=0;i<n;i++)
	{
		A[i]=rand()%1000 + 1000;
		printf("%d\t",A[i]);
	}
 printf("\nEmployee IDs available in ascending order is\n");
 printf("\n");
 merge_sort(0,n-1);
 for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
 starttime=clock();
 merge_sort(0,n-1);
 endtime=clock();
 clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 printf("\nThe run time is %f\n",clk);
 }

void merge_sort(int low,int high)
{
	int mid;
        if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(low, mid);
		merge_sort(mid+1,high); 
		merge(low,mid,high);
	}
}

void merge(int low,int mid,int high)
{
	int h,l,i,j,b[500000],k;
	h=low;
	i=low;
	j=mid+1;
	while((h<=mid)&&(j<=high))
	{
		if(A[h]<=A[j])
		{
			b[i]=A[h];
			h++;
		}
		else
		{
			b[i]=A[j];
			j++;
		}
		i++;
	}
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=A[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=A[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
		A[k]=b[k];
}
	
	
	
		
		
		
		
			


