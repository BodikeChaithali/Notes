#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int isPalindrome() {
    if (front == -1) {
        printf("Queue is empty\n");
        return 0;
    }

    int i = front;
    int j = rear;

    while (i < j) {
        if (queue[i] != queue[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }
    if (isPalindrome())
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}