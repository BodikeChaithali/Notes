#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(char inorder[], int start, int end, char value) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == value)
            return i;
    return -1;
}

struct Node* buildTree(char inorder[], char preorder[],
                       int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd)
        return NULL;

    char curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node* node = newNode(curr);

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, curr);

    node->left  = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main() {
    char inorder[]  = {'D','B','E','A','F','C'};
    char preorder[] = {'A','B','D','E','C','F'};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    int preIndex = 0;
    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("Postorder traversal: ");
    postorder(root);     // Output: D E B F C A
    printf("\n");

    return 0;
}
