#include <stdio.h>
#include <stdlib.h>

/* ------------ Definition of tree node ------------ */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* ------------ DFS function to reverse odd levels ------------ */
void dfs(struct TreeNode* a, struct TreeNode* b, int level) {
    if (!a || !b) return;

    if (level % 2 == 1) {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    dfs(a->left,  b->right, level + 1);
    dfs(a->right, b->left,  level + 1);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    if (!root) return NULL;

    dfs(root->left, root->right, 1);
    return root;
}

/* ------------ Utility: Create new node ------------ */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* ------------ Utility: Level order print ------------ */
void printLevelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = queue[front++];

        if (node) {
            printf("%d ", node->val);
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }
    printf("\n");
}

/* ------------ Free tree ------------ */
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* ------------ MAIN ------------ */
int main() {
    /*
        Example tree:
                    1
                 /     \
                2       3
              /  \     /  \
             4    5   6    7

        After reversing odd levels:
                    1
                 /     \
                3       2
              /  \     /  \
             4    5   6    7
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Before reversing odd levels (level order):\n");
    printLevelOrder(root);

    reverseOddLevels(root);

    printf("After reversing odd levels (level order):\n");
    printLevelOrder(root);

    freeTree(root);
    return 0;
}
