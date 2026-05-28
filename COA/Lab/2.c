#include <stdio.h>

int result;

int show(char *msg, int x) {
    printf("%s %d\n", msg, x);
    return x + 100;
}

void print_result(void) {
    printf("result = %d\n", result);
}

