#include <stdio.h>
#define MAX 1000

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

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // push first two numbers
    push(0);
    push(1);

    for (int i = 2; i <= n; i++) {
        int b = pop();   // top
        int a = pop();   // second top
        int c = a + b;

        // push them back in order
        push(a);
        push(b);
        push(c);
    }

    return stack[top];  // top has Fib(n)
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fibonacci not defined for negative numbers.\n");
    } else {
        int result = fibonacci(n);
        printf("Fibonacci(%d) = %d\n", n, result);
    }

    return 0;
}
