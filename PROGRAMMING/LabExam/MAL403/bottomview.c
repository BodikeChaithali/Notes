#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node structure for BFS
struct QNode {
    struct Node* node;
    int hd; // horizontal distance
};

// Queue structure
struct Queue {
    int front, rear;
    struct QNode* arr[1000];
};

int hdMap[2000];  // stores node values by HD
int visited[2000]; // for marking updated HD

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

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

void bottomView(struct Node* root) {
    if (root == NULL) return;

    // reset visited
    for (int i = 0; i < 2000; i++) visited[i] = 0;

    struct Queue q = {0, 0};

    // starting HD = 1000 offset to avoid negative index
    enqueue(&q, root, 1000);

    while (!isEmpty(&q)) {
        struct QNode* temp = dequeue(&q);
        int hd = temp->hd;
        struct Node* node = temp->node;

        // Always update the value (latest seen at level)
        hdMap[hd] = node->data;
        visited[hd] = 1;

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

// Driver Code
int main() {
    /*
            20
           /  \
         8    22
        / \     \
       5   3    25
          / \
         10 14
    */

    struct Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    printf("Bottom View: ");
    bottomView(root);

    return 0;
}
