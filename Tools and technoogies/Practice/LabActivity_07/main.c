#include<stdio.h>
#include"pallindrome.h"

int main() {
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	if(reverseNum(n)==1) printf("%d is a pallindrome\n",n);
	else printf("%d is not a pallindrome\n",n);
	return 0;
}
