#include<stdio.h>
#include<stdlib.h>

int main (int argc,char *argv[]) {
	if(argc!=2) {
		printf("Enter only one value!!\n");
		return 0;
	}
	int n=atoi(argv[1]);
	if(n==0 ||n==1) return 0;
	for(int i=2;i<n;i++) 
		if(n%i==0) return 0;
	printf("%d",n);
	return 0;
}
