#include <stdio.h>
#include <stdlib.h>

/* Definition for a binary tree node */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Prune subtrees that contain only zeros */
struct TreeNode* pruneTree(struct TreeNode* root) {
    if (!root) return NULL;

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    if (root->val == 0 && root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    return root;
}

/* Utility: create a new node */
struct TreeNode* newNode(int val) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

/* Utility: print tree (inorder) */
void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

/* Utility: free entire tree */
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    /*
         Example Tree:
                 1
                / \
               0   1
              /   / \
             0   0   1

        After pruning → only keep subtrees containing 1
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(0);
    root->left->left = newNode(0);

    root->right = newNode(1);
    root->right->left = newNode(0);
    root->right->right = newNode(1);

    printf("Original Inorder: ");
    printInorder(root);
    printf("\n");

    root = pruneTree(root);   // Perform pruning

    printf("Pruned Inorder:   ");
    printInorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
