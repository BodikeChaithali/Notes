#include <stdio.h>
#include <stdlib.h>
int getNthUgly(int n) {
    if (n <= 0) return 0;
    int *ugly = malloc(sizeof(int) * n);
    if (!ugly) return 0;
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int next2 = 2, next3 = 3, next5 = 5, next;
    for (int i = 1; i < n; i++) {
        next = next2 < next3 ? (next2 < next5 ? next2 : next5) : (next3 < next5 ? next3 : next5);
        ugly[i] = next;
        if (next == next2) { 
            i2++; 
            next2 = ugly[i2] * 2; 
        }
        if (next == next3) { 
            i3++; 
            next3 = ugly[i3] * 3; 
        }
        if (next == next5) { 
            i5++; 
            next5 = ugly[i5] * 5; 
        }
    }
    int result = ugly[n-1];
    free(ugly);
    return result;
}

int main(void) {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("%d\n", getNthUgly(n));
    return 0;
}