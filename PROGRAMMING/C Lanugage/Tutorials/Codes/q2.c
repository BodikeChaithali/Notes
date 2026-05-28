#include <stdio.h>

int main() {
    int a, b, c, d;
    int largest, second;

    // Input 4 numbers
    printf("Enter 4 numbers:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Assume a is the largest
    if (a > b) {
        largest = a;
        second = b;
    } else {
        largest = b;
        second = a;
    }

    // Compare with c
    if (c > largest) {
        second = largest;
        largest = c;
    } else if (c > second) {
        second = c;
    }

    // Compare with d
    if (d > largest) {
        second = largest;
        largest = d;
    } else if (d > second) {
        second = d;
    }

    printf("Largest number: %d\n", largest);
    printf("Second largest number: %d\n", second);

    return 0;
}
