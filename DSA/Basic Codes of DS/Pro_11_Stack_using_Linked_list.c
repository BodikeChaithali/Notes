// Stack implementation using linked list in C
#include <stdio.h>
#include <stdlib.h>

// Structure of a stack node
struct Node {
    int INFO;           // Stores the data
    struct Node* LINK;  // Points to the next node
};

struct Node* TOP = NULL;   // Points to the top of the stack
struct Node* AVAIL = NULL; // Free list pointer (optional)

// Function to create a new node
struct Node* getNode() {
    struct Node* NEW;
    if (AVAIL != NULL) {  // If free list has nodes
        NEW = AVAIL;
        AVAIL = AVAIL->LINK;
    } else {
        NEW = (struct Node*)malloc(sizeof(struct Node));
        if (NEW == NULL) {
            printf("\nSTACK OVERFLOW! Memory allocation failed.\n");
            exit(1);
        }
    }
    return NEW;
}

// Function to return a node to the free list
void freeNode(struct Node* node) {
    node->LINK = AVAIL;
    AVAIL = node;
}

// PUSH operation
void PUSH(int ITEM) {
    struct Node* NEW = getNode();
    NEW->INFO = ITEM;
    NEW->LINK = TOP;  // Point new node to previous top
    TOP = NEW;        // Update TOP
    printf("Pushed %d into stack.\n", ITEM);
}

// POP operation
void POP() {
    if (TOP == NULL) {
        printf("\nSTACK UNDERFLOW! Cannot pop.\n");
        return;
    }
    struct Node* TEMP = TOP;
    int ITEM = TEMP->INFO;
    TOP = TOP->LINK;     // Move top to the next node
    freeNode(TEMP);      // Return node to free list
    printf("Popped %d from stack.\n", ITEM);
}

// PEEK operation
void PEEK() {
    if (TOP == NULL) {
        printf("\nSTACK is empty! Nothing to peek.\n");
    } else {
        printf("Top element: %d\n", TOP->INFO);
    }
}

// DISPLAY the stack
void DISPLAY() {
    if (TOP == NULL) {
        printf("\nSTACK is empty!\n");
        return;
    }
    struct Node* TEMP = TOP;
    printf("\nCurrent Stack: ");
    while (TEMP != NULL) {
        printf("%d ", TEMP->INFO);
        TEMP = TEMP->LINK;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, ITEM;

    while (1) {
        printf("\n===== STACK MENU (Linked List) =====\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &ITEM);
                PUSH(ITEM);
                break;

            case 2:
                POP();
                break;

            case 3:
                PEEK();
                break;

            case 4:
                DISPLAY();
                break;

            case 5:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
