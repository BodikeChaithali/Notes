#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Convert int to string */
void intToStr(int num, char *str) {
    sprintf(str, "%d", num);
}

/* DFS to generate root-to-leaf paths */
void dfs(struct TreeNode* root, char** res, int* size, char* path) {
    if (!root) return;

    char valStr[12];
    intToStr(root->val, valStr);

    char newPath[1000];
    strcpy(newPath, path);

    if (strlen(path) > 0)
        strcat(newPath, "->");

    strcat(newPath, valStr);

    if (!root->left && !root->right) {
        res[*size] = strdup(newPath);  // store path
        (*size)++;
        return;
    }

    if (root->left) dfs(root->left, res, size, newPath);
    if (root->right) dfs(root->right, res, size, newPath);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** res = (char**)malloc(sizeof(char*) * 200);  // max 200 paths
    *returnSize = 0;

    char path[1000] = "";
    dfs(root, res, returnSize, path);

    return res;
}

/* Utility function for creating nodes */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* MAIN FUNCTION */
int main() {
    /*
        Creating this tree:

                1
              /   \
             2     3
              \
               5

        Expected output:
        1->2->5
        1->3
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    int returnSize;
    char** paths = binaryTreePaths(root, &returnSize);

    printf("Root-to-leaf paths:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", paths[i]);
        free(paths[i]);  // free each string
    }
    free(paths);

    return 0;
}
