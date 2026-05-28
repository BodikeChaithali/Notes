#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int x){
    Node* n = malloc(sizeof(Node));
    n->val = x;
    n->left = n->right = NULL;
    return n;
}

Node* insertNode(Node* root, int x){
    if(!root) return newNode(x);
    if(x < root->val) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

int height(Node* root) {
    if(!root) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return rh+lh+1;
}
void inorder(Node* root,int *ans,int *n) {
    if(!root) return;
    inorder(root->left,ans,n);
    ans[(*n)++]=root->val;
    inorder(root->right,ans,n);
}
int min(int a,int b) {
    return a>b?b:a;
}
int solveBST(Node* root){
    int n=height(root);
    int *ans=malloc(sizeof(int)*n);
    int i=0;
    inorder(root,ans,&i);
    int m=ans[0];
    for(int j=1;j<n;j++) {
        int end=ans[j];
        int st=ans[j-1];
        int m= min(m,(end-st));
    }
    return m;
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        Node* root = NULL;
        for(int i=0;i<n;i++){
            int x; scanf("%d",&x);
            root = insertNode(root, x);
        }
        printf("%d\n", solveBST(root));
    }
    return 0;
}