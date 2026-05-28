#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree recursively with user input
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

// Iterative inorder traversal using stack
void inorderIterative(struct Node* root) {
    struct Node* STACK[100];
    int TOP = -1;
    struct Node* PTR = root;

    printf("Inorder traversal: ");

    while (PTR != NULL || TOP != -1) {
        // Push left-most path onto stack
        while (PTR != NULL) {
            STACK[++TOP] = PTR;
            PTR = PTR->left;
        }

        // Pop node from stack
        PTR = STACK[TOP--];

        // Process node
        printf("%d ", PTR->data);

        // Move to right child
        PTR = PTR->right;
    }

    printf("\n");
}

int main() {
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();

    inorderIterative(root);

    return 0;
}
