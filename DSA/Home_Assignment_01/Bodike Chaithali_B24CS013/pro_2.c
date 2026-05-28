#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int x) {
    if (top1 == MAX - 1) return;
    stack1[++top1] = x;
}

int pop1() {
    return stack1[top1--];
}

void push2(int x) {
    if (top2 == MAX - 1) return;
    stack2[++top2] = x;
}

int pop2() {
    return stack2[top2--];
}

void enqueue(int x) {
    push1(x);
    count++;
}

void dequeue() {
    int i;
    if (top1 == -1) {
        printf("Queue is Empty\n");
        return;
    }
    for (i = 0; i < count; i++) {
        push2(pop1());
    }
    printf("Dequeued: %d\n", pop2());
    count--;
    for (i = 0; i < count; i++) {
        push1(pop2());
    }
}

void display() {
    if (top1 == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("Queue using Two Stacks\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}