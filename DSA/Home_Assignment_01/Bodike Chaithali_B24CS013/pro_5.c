#include <stdio.h>

#define n 1000
int queue[n], front = -1, rear = -1;

void enqueuec(int x) {
    if ((rear + 1) % n == front) {
        printf("Queue is full.\n");
        return;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    else if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % n;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % n;
    }
    printf("\n");
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

int isempty() {
    return (front == -1 && rear == -1);
}

int isfull() {
    return ((rear + 1) % n == front);
}

int main() {
    int choice, x;
    while (1) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.IsEmpty\n6.IsFull\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                enqueuec(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                if (isempty()) printf("Queue is empty.\n");
                else printf("Queue is not empty.\n");
                break;
            case 6:
                if (isfull()) printf("Queue is full.\n");
                else printf("Queue is not full.\n");
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}