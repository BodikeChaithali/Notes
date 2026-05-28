// Stack implementation using array in C
#include <stdio.h>
#include <stdlib.h>

int *STACK;   // Pointer for dynamic stack allocation
int TOP = 0;  // Initially stack is empty
int MAXSTK;   // Will be given by the user

// Function to PUSH an item into the stack
void PUSH(int ITEM) {
    if (TOP == MAXSTK) {
        printf("\nSTACK OVERFLOW! Cannot push %d\n", ITEM);
        return;
    }
    TOP = TOP + 1;
    STACK[TOP] = ITEM;
    printf("Pushed %d into stack.\n", ITEM);
}

// Function to POP an item from the stack
void POP() {
    if (TOP == 0) {
        printf("\nSTACK UNDERFLOW! Cannot pop.\n");
        return;
    }
    int ITEM = STACK[TOP];
    TOP = TOP - 1;
    printf("Popped %d from stack.\n", ITEM);
}

// Function to PEEK at the top element
void PEEK() {
    if (TOP == 0) {
        printf("\nSTACK is empty! Nothing to peek.\n");
    } else {
        printf("Top element: %d\n", STACK[TOP]);
    }
}

// Function to DISPLAY all stack elements
void DISPLAY() {
    if (TOP == 0) {
        printf("\nSTACK is empty!\n");
        return;
    }
    printf("\nCurrent Stack: ");
    for (int i = 1; i <= TOP; i++) {
        printf("%d ", STACK[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, ITEM;

    // Ask user for maximum stack size
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &MAXSTK);

    // Allocate memory dynamically for stack
    STACK = (int *)malloc((MAXSTK + 1) * sizeof(int));

    if (STACK == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        printf("\n===== STACK MENU =====\n");
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
                free(STACK); // Free allocated memory
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
