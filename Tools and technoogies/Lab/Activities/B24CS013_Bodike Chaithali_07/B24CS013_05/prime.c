#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 2; i < n/2 ; i ++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    int num = atoi(argv[1]);
    if (isPrime(num)) {
        printf("%d\n", num);
    }
    return 0;
}
