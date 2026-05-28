#include <stdio.h>
#define MAX 5  // size of queue

int queue[MAX];
int FRONT = -1, REAR = -1;

// Function to insert an element (Enqueue)
void enqueue(int item) {
    // Check for Overflow
    if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1)) {
        printf("OVERFLOW\n");
        return;
    }

    // Find new REAR position
    if (FRONT == -1) { // Queue empty
        FRONT = REAR = 0;
    } else if (REAR == MAX - 1) {
        REAR = 0;
    } else {
        REAR = REAR + 1;
    }

    // Insert item
    queue[REAR] = item;
    printf("%d enqueued\n", item);
}

// Function to delete an element (Dequeue)
void dequeue() {
    int item;
    // Check for Underflow
    if (FRONT == -1) {
        printf("UNDERFLOW\n");
        return;
    }

    // Access front element
    item = queue[FRONT];
    printf("%d dequeued\n", item);

    // Update FRONT
    if (FRONT == REAR) { // Only one element
        FRONT = REAR = -1;
    } else if (FRONT == MAX - 1) {
        FRONT = 0;
    } else {
        FRONT = FRONT + 1;
    }
}

// Function to display queue
void display() {
    if (FRONT == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    int i = FRONT;
    while (1) {
        printf("%d ", queue[i]);
        if (i == REAR)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, item;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
