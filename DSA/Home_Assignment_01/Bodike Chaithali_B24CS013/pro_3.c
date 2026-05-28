#include <stdio.h>
#define MAX 10000

int main() {
    int n, serviceTimes[MAX], waitingTime = 0, totalWaitingTime = 0;

    printf("Enter number of customers: ");
    scanf("%d", &n);

    printf("Enter service times of customers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &serviceTimes[i]);
    }

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime;
        waitingTime += serviceTimes[i];
    }

    printf("Total Waiting Time = %d\n", totalWaitingTime);

    return 0;
}
