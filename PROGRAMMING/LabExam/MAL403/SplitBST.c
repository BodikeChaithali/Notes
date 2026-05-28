#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* r, int v) {
    if (!r) return newNode(v);
    if (v < r->data) r->left = insert(r->left, v);
    else r->right = insert(r->right, v);
    return r;
}

void splitBST(struct Node* root, int K,
              struct Node** t1, struct Node** t2) {
    if (!root) { *t1 = *t2 = NULL; return; }

    if (root->data < K) {
        splitBST(root->right, K, &root->right, t2);
        *t1 = root;
    } else {
        splitBST(root->left, K, t1, &root->left);
        *t2 = root;
    }
}

void inorder(struct Node* r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
}

int main() {
    int vals[] = {60,40,80,20,50,70,90};
    int n = 7;
    struct Node *root = NULL;

    for(int i=0;i<n;i++)
        root = insert(root, vals[i]);

    struct Node *T1, *T2;
    int K = 60;
    splitBST(root, K, &T1, &T2);

    printf("T1 (<K): "); inorder(T1);
    printf("\nT2 (>=K): "); inorder(T2);
    return 0;
}
