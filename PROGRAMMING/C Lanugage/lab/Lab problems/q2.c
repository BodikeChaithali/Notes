#include<stdio.h>
 
  int main () {
  
	  int n;
	  printf("n=");
	  scanf("%d",&n);
          printf("THE TRIANGULAR SERIES IS:\n");
	  for(int i=1;i<n;i++)
	  {
		  int a;
	           a=i*(i+1)/2;
		  printf("%d\n",a);
         } 

	return 0;  
  }
