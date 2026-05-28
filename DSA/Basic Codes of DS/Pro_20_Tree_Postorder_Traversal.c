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

// Iterative postorder traversal using stack
void postorderIterative(struct Node* root) {
    struct Node* STACK[100];
    int TOP = -1;
    struct Node* PTR = root;
    struct Node* lastVisited = NULL;

    printf("Postorder traversal: ");

    while (PTR != NULL || TOP != -1) {
        // Step 2: Push left-most path
        while (PTR != NULL) {
            STACK[++TOP] = PTR;
            PTR = PTR->left;
        }

        struct Node* peekNode = STACK[TOP];
        // If right child exists and not visited yet
        if (peekNode->right != NULL && lastVisited != peekNode->right) {
            PTR = peekNode->right;
        } else {
            printf("%d ", peekNode->data);  // PROCESS
            lastVisited = peekNode;
            TOP--;  // Pop node
        }
    }

    printf("\n");
}

int main() {
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();

    postorderIterative(root);

    return 0;
}
