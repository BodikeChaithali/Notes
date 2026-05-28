#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue implementation using array
struct Node* queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Level Order Traversal Function
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}

// Driver Code
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}
