#include <stdio.h>

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int count = 0;
    int num = 2;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            int a = 0;
            for (int k = 2; k * k <= num; k++) {
                if (num % k == 0) {
                    a = 1;
                    break;
                }
            }
            if (a == 0) {
                printf("%d ", num);
                count++;
            }
            num++;
        }
        printf("\n");
    }

    return 0;
}

