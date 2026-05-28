#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void swapTree(struct Node* root) {
    if (root == NULL) return;

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapTree(root->left);
    swapTree(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder Before Swap: ");
    inorder(root);

    swapTree(root);

    printf("\nInorder After Swap: ");
    inorder(root);

    return 0;
}
