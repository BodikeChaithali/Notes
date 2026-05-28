#include <stdio.h>

int decimaltobinary(int n) {

    if (n > 1)
    { 
	    int a;
	    a = n/2;
        decimaltobinary(a);
    }
    int b;
    b = n % 2;
    printf("%d", b);
}

int main() {

    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Binary equivalent: ");

    decimaltobinary(num);

    printf("\n");

    return 0;
}
