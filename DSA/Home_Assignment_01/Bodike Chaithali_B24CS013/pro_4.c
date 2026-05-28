#include<stdio.h>
#define n 10000

int queue[n], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == n - 1) {
        printf("Overflow!!\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
}

void reverseFirstKElements(int k) {
    if (front == -1) {
        printf("Queue is empty!!\n");
        return;
    }
    if (k > rear - front + 1) {
        printf("Invalid value!!\n");
        return;
    }
    int start = front;
    int end = front + k - 1;
    while (start < end) {
        int temp = queue[start];
        queue[start] = queue[end];
        queue[end] = temp;
        start++;
        end--;
    }
}

void display() {
    if (rear == -1) {
        printf("Queue is empty!\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch = 1, value, k;
    while (ch == 1) {
        printf("Enter the value: ");
        scanf("%d", &value);
        enqueue(value);
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &ch);
    }
    printf("k = ");
    scanf("%d", &k);
    reverseFirstKElements(k);
    display();
    return 0;
}
