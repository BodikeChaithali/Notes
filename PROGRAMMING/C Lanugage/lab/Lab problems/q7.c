#include <stdio.h>

int main() {
    int a, b, c = 0;
    printf("Enter two integers a and b (a <= b <= 1000): ");
    scanf("%d %d", &a,&b);
    for (int i = a; i <= b; i++) {
        for (int j = i; j <= b; j++) {
            if (j % i == 0) {  
                c++;
            }
        }
    }
    printf("Number of pairs (i, j) such that i divides j: %d\n", c);

    return 0;
}
