// Postfix Expression Evaluation in C
// This program evaluates a postfix expression using a stack 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("UNDERFLOW\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *exp) {
    int i = 0;
    char ch;
    int A, B, result;

    strcat(exp, ")");  // Append ')' sentinel

    while ((ch = exp[i]) != ')') {
        if (isdigit(ch)) {
            push(ch - '0');   // Convert char → int
        } else {
            // Operator encountered
            A = pop();
            B = pop();
            switch (ch) {
                case '+': result = B + A; break;
                case '-': result = B - A; break;
                case '*': result = B * A; break;
                case '/': result = B / A; break;
                case '^': result = 1;
                          for (int k = 0; k < A; k++) result *= B;
                          break;
                default:
                    printf("Invalid Operator: %c\n", ch);
                    exit(1);
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter a Postfix Expression: ");
    scanf("%s", exp);

    int value = evaluatePostfix(exp);
    printf("Final Result = %d\n", value);
    return 0;
}
