#include<stdio.h>
#include"pallindrome.h"

int main () {
	int n;
	printf("Enter a number: ");
	if (scanf("%d",&n) != 1) return 1;

	if (is_pallindrome(n)) 
		printf("%d is a pallindrome.\n",n);
	else 
		printf("%d is not a pallindrome.\n",n);
	return 0;
}
