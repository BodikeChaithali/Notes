#include <stdio.h>
#include <stdlib.h>

int fillCups(int* amount, int amountSize) {
    int total = amount[0] + amount[1] + amount[2];

    int maxVal = amount[0];
    if (amount[1] > maxVal) maxVal = amount[1];
    if (amount[2] > maxVal) maxVal = amount[2];

    // Minimum time = max(maxVal, ceil(total / 2))
    int required = (total + 1) / 2;

    return maxVal > required ? maxVal : required;
}

int main() {
    int amount[3];

    printf("Enter 3 cup amounts (cold, warm, hot): ");
    for (int i = 0; i < 3; i++)
        scanf("%d", &amount[i]);

    int result = fillCups(amount, 3);

    printf("Minimum time required = %d\n", result);

    return 0;
}
