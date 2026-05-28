#include <stdio.h>
#define MAX 100   // maximum stack size

// Stack functions
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int factorial(int n) {
    int fact = 1;

    // Step 1: Push numbers onto stack
    while (n > 0) {
        push(n);
        n--;
    }

    // Step 2: Pop and multiply
    while (top != -1) {
        fact *= pop();
    }

    return fact;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = factorial(n);
        printf("Factorial of %d = %d\n", n, result);
    }

    return 0;
}
