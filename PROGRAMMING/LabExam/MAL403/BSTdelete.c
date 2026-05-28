#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

struct BSTNode* newBSTNode(int key) {
    struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct BSTNode* insert(struct BSTNode* root, int key) {
    if (root == NULL) return newBSTNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

struct BSTNode* minValueNode(struct BSTNode* node) {
    struct BSTNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct BSTNode* deleteNode(struct BSTNode* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // node to delete found
        if (root->left == NULL) {
            struct BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode* temp = root->left;
            free(root);
            return temp;
        }

        // two children: use inorder successor
        struct BSTNode* temp = minValueNode(root->right);
        root->key = temp->key;                 // copy value
        root->right = deleteNode(root->right,  // delete successor
                                 temp->key);
    }
    return root;
}

void inorderBST(struct BSTNode* root) {
    if (root == NULL) return;
    inorderBST(root->left);
    printf("%d ", root->key);
    inorderBST(root->right);
}

int main() {
    int keys[] = {45,25,65,15,35,55,75,5,20,30,40};
    int n = sizeof(keys)/sizeof(keys[0]);

    struct BSTNode* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    printf("Inorder before deletion: ");
    inorderBST(root);
    printf("\n");

    root = deleteNode(root, 25);

    printf("Inorder after deleting 25: ");
    inorderBST(root);
    printf("\n");
    // From this inorder you can draw the final tree.

    return 0;
}