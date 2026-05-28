#include<stdio.h>
#include<functions.h>

int main () {
	int a,b;
	if (scanf("%d %d", &a, &b) != 2) {
    printf("Invalid input\n");
    return 1;
}
	printf("Addition: %d\nSubtraction: %d\n",add(a,b),sub(a,b));
	return 0;
}
