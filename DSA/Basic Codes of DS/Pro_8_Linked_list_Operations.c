#include <stdio.h>
#include <stdlib.h>

int *INFO;    // Dynamic array for data
int *LINK;    // Dynamic array for next pointers
int START = -1;  // Start of linked list
int AVAIL = 0;   // Points to first free node
int MAXSIZE;     // Maximum number of nodes, entered by user

// Initialize free list dynamically
void initializeList() {
    for (int i = 0; i < MAXSIZE - 1; i++) {
        LINK[i] = i + 1;  // Next free node
    }
    LINK[MAXSIZE - 1] = -1; // End of free list
    AVAIL = 0;
}

// Function to get a free node from AVAIL list
int getNode() {
    if (AVAIL == -1) {
        printf("OVERFLOW! No more free nodes available.\n");
        return -1;
    }
    int NEW = AVAIL;
    AVAIL = LINK[AVAIL]; // Remove from free list
    return NEW;
}

// Function to return a node to AVAIL list
void freeNode(int LOC) {
    LINK[LOC] = AVAIL;
    AVAIL = LOC;
}

// Insert at the beginning
void insertAtBeginning(int ITEM) {
    int NEW = getNode();
    if (NEW == -1) return;

    INFO[NEW] = ITEM;
    LINK[NEW] = START;
    START = NEW;
    printf("%d inserted at the beginning.\n", ITEM);
}

// Insert at the end
void insertAtEnd(int ITEM) {
    int NEW = getNode();
    if (NEW == -1) return;

    INFO[NEW] = ITEM;
    LINK[NEW] = -1;

    if (START == -1) {
        START = NEW;
    } else {
        int PTR = START;
        while (LINK[PTR] != -1) {
            PTR = LINK[PTR];
        }
        LINK[PTR] = NEW;
    }
    printf("%d inserted at the end.\n", ITEM);
}

// Insert after a given location
void insertAfter(int LOC, int ITEM) {
    if (LOC < 0 || LOC >= MAXSIZE) {
        printf("Invalid location!\n");
        return;
    }

    int NEW = getNode();
    if (NEW == -1) return;

    INFO[NEW] = ITEM;
    LINK[NEW] = LINK[LOC];
    LINK[LOC] = NEW;
    printf("%d inserted after location %d.\n", ITEM, LOC);
}

// Delete a node by value
void deleteNode(int ITEM) {
    if (START == -1) {
        printf("UNDERFLOW! List is empty.\n");
        return;
    }

    int LOC = START, LOCP = -1;

    // Search for ITEM
    while (LOC != -1 && INFO[LOC] != ITEM) {
        LOCP = LOC;
        LOC = LINK[LOC];
    }

    if (LOC == -1) {
        printf("ITEM %d not found!\n", ITEM);
        return;
    }

    // If deleting the first node
    if (LOCP == -1) {
        START = LINK[START];
    } else {
        LINK[LOCP] = LINK[LOC];
    }

    freeNode(LOC);
    printf("Deleted ITEM %d successfully.\n", ITEM);
}

// Display the linked list
void displayList() {
    if (START == -1) {
        printf("List is empty!\n");
        return;
    }

    int PTR = START;
    printf("Linked List: ");
    while (PTR != -1) {
        printf("%d ", INFO[PTR]);
        PTR = LINK[PTR];
    }
    printf("\n");
}

// Main function
int main() {
    int choice, item, loc;

    // Ask user for maximum size
    printf("Enter the maximum size of the linked list: ");
    scanf("%d", &MAXSIZE);

    // Dynamically allocate memory for INFO and LINK arrays
    INFO = (int *)malloc(MAXSIZE * sizeof(int));
    LINK = (int *)malloc(MAXSIZE * sizeof(int));

    if (INFO == NULL || LINK == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize free list
    initializeList();

    // Menu-driven program
    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Location\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                insertAtBeginning(item);
                break;

            case 2:
                printf("Enter item: ");
                scanf("%d", &item);
                insertAtEnd(item);
                break;

            case 3:
                printf("Enter location index: ");
                scanf("%d", &loc);
                printf("Enter item: ");
                scanf("%d", &item);
                insertAfter(loc, item);
                break;

            case 4:
                printf("Enter item to delete: ");
                scanf("%d", &item);
                deleteNode(item);
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Exiting...\n");
                free(INFO);
                free(LINK);
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
