#include<stdio.h>

    int main () {
    int n,a,max,min;
      printf("size of the list is:");
      scanf("%d",&n);
      printf("enter the list:\n");
      scanf("%d",&a);
      max=min=a;
      for( int i=1;i<n;i++) {
      scanf("%d",&a);
      if(a>max)  {
	      max=a;
          }
      else if(a<min) {
         min=a;
          }
      }
      printf("the maximum number is %d.\n",max);
      printf("the minimum number is %d.\n",min);
       return 0;
    } 
