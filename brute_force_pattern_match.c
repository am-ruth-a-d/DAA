#include<stdio.h>
#include<string.h>
#include<time.h>
char t[100],p[50];
void main()
{
     double clk;
     clock_t starttime,endtime;
     int pos;
     printf("\nEnter the String \n");
     scanf("%s",t);
     printf("\nEnter the word to be searched \n");
     scanf("%s",p);
     starttime=clock();
     pos=brute_force();
     endtime=clock();
     if(pos==-1)
           printf("\n%s word not found in string\n",p);
      else
           printf("\n%s word found at index %d\n",p,pos);
     clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
     printf("\nRun time = %f\n\n",clk);
}
int brute_force()
{
       int n,j,m,i;
       n=strlen(t);
       m=strlen(p);
       for(i=0;i<n;i++)
      {
             j=0;
             while(j<m && t[i+j]==p[j])
            {
                     j++;
                    if(j==m)
                            return i+1; 
            }
      }
      return -1;  
}
