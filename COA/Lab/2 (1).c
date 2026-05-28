#include<stdio.h>

extern int add(int, int);

int main() {
    int sum = add(10, 20);
    printf("Sum = %d\n", sum);
    return 0;
}