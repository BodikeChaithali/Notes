#include<stdio.h>

int main() {
    int n,e;
    printf("Enter the no.of verctices: ");
    scanf("%d",&n);
    printf("Enter the no,of Edges: ");
    scanf("%d",&e);
    char vertices[n];
    printf("Enter the vertices:\n");
    for(int i=0;i<n;i++) 
        scanf(" %c",&vertices[i]);
    int adj[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) 
            adj[i][j]=0;
    }
    printf("Enter the Edges (source destination):\n");
    for(int i=0;i<e;i++) {
        char u,v;
        scanf(" %c %c",&u,&v);
        int ui=-1,vi=-1;
        for(int j=0;j<n;j++) {
            if(vertices[j]==u) ui=j;
            if(vertices[j]==v) vi=j;
        }
        if(ui!=-1 && vi!=-1) {
            adj[ui][vi]=1;
            adj[vi][ui]=1;
        }
    }
    printf("Adjacency Matrix:\n");
    printf("  ");
    for(int i=0;i<n;i++) 
        printf("%c ",vertices[i]);
    printf("\n");
    for(int i=0;i<n;i++) {
        printf("%c ",vertices[i]);
        for(int j=0;j<n;j++) 
            printf("%d ",adj[i][j]);
        printf("\n");
    }
    return 0;
}