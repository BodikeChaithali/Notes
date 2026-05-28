#include <stdio.h>
#include <math.h>

int countdigits(int n) {
    int c = 0;
    while (n != 0) {
        c++;
        n = n/ 10;
    }
    return c;
}

int isarmstrong(int n) {
    int a = 0, originalnum = n;
    int digits = countdigits(n);
    
    while (n != 0) {
        int digit = n % 10;
        a += pow(digit, digits);
        n = n/10;
    }
    
    return (a == originalnum);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if (isarmstrong(n)) {
        printf("%d is an Armstrong number.\n", n);
    } else {
        printf("%d is not an Armstrong number.\n", n);
    }
    
    return 0;
}
