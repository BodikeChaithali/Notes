#include<stdio.h>

int main () {

	int num,c,a,b=0;
	//c=number
	//a=reminder of number
	//b=result
	printf("enter a number ");
	scanf("%d",&num);
	c=num;
	while(c != 0) {
		a=c%10;
		b=b+a*a*a;
		c=c/10;
	}
	if(b == num)
		printf("%d is an armstrong number.\n",num);
	else
	    printf("%d is not an armstrong number.\n",num);
	return 0;

}
