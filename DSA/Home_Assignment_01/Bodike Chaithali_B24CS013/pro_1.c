#include <stdio.h>
#define N 10000

int queue[N], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == N - 1) {
        printf("Overflow!!\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void rotatektimes(int k, int m) {
    if (m <= 0) return;
    k = k % m;  
    if (k == 0) return;
    int temp[m];
    for (int i = 0; i < k; i++) {
        temp[i] = queue[m - k + i];
    }
    for (int i = m - 1; i >= k; i--) {
        queue[i] = queue[i - k];
    }
    for (int i = 0; i < k; i++) {
        queue[i] = temp[i];
    }
}

int main() {
    int length;
    printf("Enter the size of the queue: ");
    scanf("%d", &length);

    if (length <= 0 || length > N) {
        printf("Invalid size!\n");
        return 0;
    }

    printf("Enter values: ");
    for (int i = 0; i < length; i++) {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }

    int k;
    printf("Enter how many times to rotate: ");
    scanf("%d", &k);

    rotatektimes(k, length);
    printf("Queue after rotation:\n");
    display();

    return 0;
}
