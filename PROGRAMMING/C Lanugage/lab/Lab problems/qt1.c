#include<stdio.h>

int main () {
     
	int a,b = 0, c = 1,d;
	printf("a=");
	scanf("%d",&a);
	

	printf("FIBONACCI SERIES IS :\n");

	for (int i = 1;i <= a;i++)
	{
	        d=b+c;
		b=c;
		c=d;
		printf("%d,\n",b);
        }
	return 0;
}
