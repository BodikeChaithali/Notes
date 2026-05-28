// Doubly Linked List implementation in C
#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        printf("%d inserted at beginning.\n", value);
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    printf("%d inserted at beginning.\n", value);
}

// Insert at the end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        printf("%d inserted at end.\n", value);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    printf("%d inserted at end.\n", value);
}

// Insert after a given position (1-based index)
void insertAfterPosition(int position, int value) {
    if (head == NULL) {
        printf("List is empty! Inserting at beginning.\n");
        insertAtBeginning(value);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d not found. Inserting at end.\n", position);
        insertAtEnd(value);
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("%d inserted after position %d.\n", value, position);
}

// Delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("UNDERFLOW! List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("UNDERFLOW! List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // If there is only one node
    if (temp->next == NULL) {
        printf("Deleted %d from end.\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    // Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

// Delete by value
void deleteByValue(int value) {
    if (head == NULL) {
        printf("UNDERFLOW! List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Search for the value
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }

    // If deleting head
    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("Deleted %d successfully.\n", value);
        free(temp);
        return;
    }

    // If deleting the last node
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        printf("Deleted %d successfully.\n", value);
        free(temp);
        return;
    }

    // If deleting a middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted %d successfully.\n", value);
    free(temp);
}

// Display list forward
void displayForward() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display list backward
void displayBackward() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    // Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main menu-driven function
int main() {
    int choice, value, position;

    while (1) {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfterPosition(position, value);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromEnd();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
