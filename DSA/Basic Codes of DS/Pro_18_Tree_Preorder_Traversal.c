#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for iterative traversal
struct Stack {
    struct Node* items[100];
    int top;
};

// Push node onto stack
void push(struct Stack* s, struct Node* node) {
    s->items[++(s->top)] = node;
}

// Pop node from stack
struct Node* pop(struct Stack* s) {
    return s->items[(s->top)--];
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from user input
struct Node* buildTree() {
    int val;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1) return NULL;

    struct Node* root = newNode(val);
    printf("Enter left child of %d:\n", val);
    root->left = buildTree();
    printf("Enter right child of %d:\n", val);
    root->right = buildTree();

    return root;
}

// Iterative preorder traversal using stack
void preorderIterative(struct Node* root) {
    if (root == NULL) return;

    struct Stack s;
    s.top = -1;
    push(&s, root);

    printf("Preorder traversal: ");
    while (!isEmpty(&s)) {
        struct Node* curr = pop(&s);
        printf("%d ", curr->data);

        // Push right first so left is processed first
        if (curr->right) push(&s, curr->right);
        if (curr->left) push(&s, curr->left);
    }
    printf("\n");
}

int main() {
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();

    preorderIterative(root);

    return 0;
}
