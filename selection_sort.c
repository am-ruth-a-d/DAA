#include <stdio.h>
#include<time.h>
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void selectionSort(int a[], int n)
{
    int i, j, min;
 
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[min])
            min = j;
 
        swap(&a[min], &a[i]);
    }
}
 
 
int main()
{
    double clk;
    int n;
    clock_t starttime,endtime;
    srand(time(0));
    printf("\n\nEnter n\n\n");
    scanf("%d",&n);
    int a[n],i;
    printf("\nRandom number generated are\n");
    for(i=0;i<n;i++)
	{
		a[i]=rand()%1000 + 1000;
		printf("%d\t",a[i]);
	}
    printf("\n");
    starttime=clock();
    selectionSort(a, n);
    endtime=clock();
    printf("\nSorted array: \n");
    for (i=0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("\nThe run time is %f\n",clk);
    return 0;
}
