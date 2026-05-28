#include<stdio.h>

int prime(int x){
	for(int i=2;i<x;i++){
		if(x%i==0)
			return 0;
	}
	return 1;
} 

int main () {
      int k=2,count=0;
      int n;
      scanf("%d",&n);

      while(1){
	      if(count==n)
		      break;
	      if(prime(k)){
		      printf("%d\n",k);
		      count++;}
	      k++;
      }
}
