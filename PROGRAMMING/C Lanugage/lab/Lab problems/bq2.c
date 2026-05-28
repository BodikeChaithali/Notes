#include<stdio.h>

int computehcf(int a,int b) {
	while (b!=0)
	{
		int c =b;
		b = a % b;
		a=c; 
	}

       return a;
}
int coprime(int a,int b)
           {
		   return (computehcf(a,b)==1);
	   }
int main () {

	int c,d;
	printf("enter the value of c:");
	scanf("%d",&c);
	printf("enter the value of d:");
	scanf("%d",&d);

	if(coprime(c,d)) 
	{
		printf("%d and %d are coprimes.\n",c,d);
	}
	else 
	{ 
		printf("%d and %d are not coprimes.\n",c,d);
	}
	return 0;
}

