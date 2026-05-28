#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for Level Order Traversal
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

void leftView(struct Node* root) {
    if (!root) return;

    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front; // total nodes in current level

        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();

            // print first node of each level
            if (i == 0)
                printf("%d ", temp->data);

            if (temp->left)
                enqueue(temp->left);
            if (temp->right)
                enqueue(temp->right);
        }
    }
}

int main() {
    /* Tree used:
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

    printf("Left View: ");
    leftView(root);

    return 0;
}
