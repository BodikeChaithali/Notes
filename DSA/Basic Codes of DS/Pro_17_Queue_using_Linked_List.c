#include <stdio.h>
#include <stdlib.h>

int *INFO;   // Data storage
int *LINK;   // Links between nodes
int FRONT = -1, REAR = -1;  // Queue pointers
int AVAIL = 0;              // Free list pointer
int MAX;                     // Maximum number of nodes

// Initialize free list
void init(int n) {
    MAX = n;
    INFO = (int *)malloc(sizeof(int) * MAX);
    LINK = (int *)malloc(sizeof(int) * MAX);

    for (int i = 0; i < MAX - 1; i++) {
        LINK[i] = i + 1;
    }
    LINK[MAX - 1] = -1;
    AVAIL = 0;
}

// Enqueue operation
void enqueue(int ITEM) {
    if (AVAIL == -1) {  // No free node
        printf("OVERFLOW\n");
        return;
    }

    int NEW = AVAIL;
    AVAIL = LINK[AVAIL];

    INFO[NEW] = ITEM;
    LINK[NEW] = -1;

    if (FRONT == -1) {  // Queue empty
        FRONT = REAR = NEW;
    } else {
        LINK[REAR] = NEW;
        REAR = NEW;
    }

    printf("%d enqueued\n", ITEM);
}

// Dequeue operation
void dequeue() {
    if (FRONT == -1) {  // Queue empty
        printf("UNDERFLOW\n");
        return;
    }

    int TEMP = FRONT;
    int ITEM = INFO[TEMP];

    FRONT = LINK[TEMP];
    if (FRONT == -1)  // Queue became empty
        REAR = -1;

    LINK[TEMP] = AVAIL;
    AVAIL = TEMP;

    printf("%d dequeued\n", ITEM);
}

// Display queue
void display() {
    if (FRONT == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = FRONT;
    while (i != -1) {
        printf("%d ", INFO[i]);
        i = LINK[i];
    }
    printf("\n");
}

int main() {
    int choice, item, n;

    printf("Enter maximum number of nodes: ");
    scanf("%d", &n);
    init(n);  // Initialize AVAIL list

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
                free(INFO);
                free(LINK);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
