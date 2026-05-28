#include<stdio.h>
#include<stdlib.h>

int main (int argc,char *argv[]) {
	if(argc!=3) {
		printf("Enter exactly teo inputs!!\n");
		return 0;
	}
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	printf("Sum: %d\n",a+b);
	return 0;
}
