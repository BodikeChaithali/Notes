#include<stdio.h>
#include<stdlib.h>

struct Node {
    char vertex;
    struct Node *next;
};

struct Node* createNode(char v) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}

int getIndex(char vertices[], int n, char v) {
    for (int i=0; i<n; i++)
        if (vertices[i] == v)
            return i;
    return -1;
}

int main() {
    int n,e;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    char vertices[n];
    printf("Enter the vertices:\n");
    for(int i=0;i<n;i++) 
        scanf(" %c",&vertices[i]);
    struct Node* adj[n];
    for (int i=0;i<n;i++) adj[i]=NULL;
    printf("Enter edges (source destination):\n");
    for(int i=0;i<e;i++) {
        char u, v;
        scanf(" %c %c", &u, &v);
        int ui = getIndex(vertices, n, u);
        int vi = getIndex(vertices, n, v);
        struct Node* node = createNode(v);
        node->next = adj[ui];
        adj[ui] = node;
        node = createNode(u);
        node->next = adj[vi];
        adj[vi] = node;
    }

    printf("Adjacency List:\n");
    for(int i=0;i<n;i++) {
        struct Node *temp=adj[i];
        printf("%c -> ",vertices[i]);
        while(temp) {
            printf("%c ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
    return 0;
}