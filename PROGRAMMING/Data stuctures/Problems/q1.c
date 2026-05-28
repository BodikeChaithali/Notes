#include<stdio.h>

int main() {
	int n;
	printf("n = ");
	scanf("%d",&n);
	int count=1,i=2;
	while(count<=n) {
		if(i%2==0 || i%3==0 || i%5==0) count++;
		if(count==n) break;
		i++;
	}
	printf("%d\n",i);
	return 0;
}
