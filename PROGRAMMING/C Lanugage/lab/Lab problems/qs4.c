#include <stdio.h>

int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f=f*i;
    }
    return f;
}

int isstrong(int num) {
    int sum = 0, originalnum = num;

    while (num > 0) {
        int digit = num % 10;
        sum = sum + factorial(digit); 
        num = num/10;
    }

    return (sum == originalnum);
}

void checkstrongnumber() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isstrong(num)) {
        printf("%d is a strong number.\n", num);
    } else {
        printf("%d is not a strong number.\n", num);
    }
}
int main() {
    checkstrongnumber();
    return 0;
}

