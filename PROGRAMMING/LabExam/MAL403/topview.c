#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue structure for BFS (stores node + horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    int front, rear, size;
    struct QNode* arr[1000];
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear] = (struct QNode*)malloc(sizeof(struct QNode));
    q->arr[q->rear]->node = node;
    q->arr[q->rear]->hd = hd;
    q->rear++;
}

struct QNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// For mapping horizontal distance -> first seen node index
int hdMap[2000];     // to store node values
int visited[2000];   // to check if a HD is already printed

void topView(struct Node* root) {
    if (!root) return;

    for (int i = 0; i < 2000; i++) visited[i] = 0;

    struct Queue q = {0, 0, 1000};
    enqueue(&q, root, 1000);  // hd offset to avoid negative index

    while (!isEmpty(&q)) {
        struct QNode* temp = dequeue(&q);
        int hd = temp->hd;
        struct Node* node = temp->node;

        // If this HD is not printed before, print & mark visited
        if (!visited[hd]) {
            visited[hd] = 1;
            hdMap[hd] = node->data;
        }

        if (node->left)
            enqueue(&q, node->left, hd - 1);

        if (node->right)
            enqueue(&q, node->right, hd + 1);
    }

    // Print from left-most to right-most
    for (int i = 0; i < 2000; i++) {
        if (visited[i]) {
            printf("%d ", hdMap[i]);
        }
    }
}

// Driver code
int main() {
    // Sample Tree:
    //       1
    //     /   \
    //    2     3
    //     \   / \
    //      4 5   6

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);

    printf("Top View: ");
    topView(root);

    return 0;
}
