#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % SIZE == front;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
    return val;
}

int peek() {
    if (isEmpty()) return -1;
    return queue[front];
}

int main() {
    enqueue(10);
    enqueue(20);
    printf("%d ", dequeue());
    enqueue(40);
    printf("%d ", dequeue());
    return 0;
}
