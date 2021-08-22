#include<stdio.h>
#include<time.h>
int main()
{	char choice;
	int n,i,j,key,temp,pos=0;
	double clk;
	clock_t starttime,endtime;
	srand(time(0));
	printf("\n\nWELCOME TO DIGISHOP\n\n");
	printf("Would you like to see the availability of product before continuing? Y/N:\n");
	scanf("%c",&choice);
	if(choice=='n'||choice=='N')
	return 0;
	printf("Enter the number of products in stock\n");
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	{
		A[i]=rand()%1000 +1000;
	}
	for(i=0;i<n-1;i++)
 		for(j=0;j<n-1-i;j++)
 			if(A[j+1]<A[j])
 			{
 		  	temp=A[j];
 		  	A[j]=A[j+1];
 		  	A[j+1]=temp;
 		 	}
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);
	printf("\nEnter product ID to be searched\n");
	scanf("%d",&key);
	pos=binarySearch(A,0,n-1,key);
	if (pos==-1)
		printf("Product not available\n");
	else
		printf("%d is found at position %d",key,pos+1);
      starttime=clock();
	binarySearch(A,0,n-1,key);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 	printf("\nThe run time is %f\n",clk);
 	}
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
         if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
