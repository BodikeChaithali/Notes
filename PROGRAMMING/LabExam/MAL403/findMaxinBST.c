#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertinBST(struct Node *root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insertinBST(root->left, val);
    else
        root->right = insertinBST(root->right, val);

    return root;
}

int findMaxinBST(struct Node *root) {
    if (root == NULL)
        return -1;

    struct Node *current = root;
    while (current->right != NULL)
        current = current->right;

    return current->data;
}

int main() {
    int n;
    printf("Enter number of nodes in tree: ");
    scanf("%d", &n);

    struct Node *head = NULL;

    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        head = insertinBST(head, key);
    }

    printf("Maximum element in BST: %d\n", findMaxinBST(head));
    return 0;
}
