#include<stdio.h>

void swap(int *a,int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main () {
	int a,b;
	printf("Enter two values:");
	scanf("%d%d",&a,&b);
	swap(&a,&b);
	printf("values of a and b after swapping : a=%d,b=%d\n",a,b);

	return 0;
}
