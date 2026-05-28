#include <stdlib.h>

void dfs(int u,int n,int **adj,int *adjSizes,int *visited,int *nodeCount,int *edgeCount) {
    visited[u]=1;
    (*nodeCount)++;
    (*edgeCount)+=adjSizes[u];
    for(int i=0;i<adjSizes[u];i++) {
        int v=adj[u][i];
        if(!visited[v]) dfs(v,n,adj,adjSizes,visited,nodeCount,edgeCount);
    }
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    int *adjSizes=(int*)calloc(n,sizeof(int));
    for(int i=0;i<edgesSize;i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        adjSizes[u]++;
        adjSizes[v]++;
    }

    int **adj=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) {
        adj[i]=(int*)malloc(adjSizes[i]*sizeof(int));
        adjSizes[i]=0;
    }

    for(int i=0;i<edgesSize;i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u][adjSizes[u]++]=v;
        adj[v][adjSizes[v]++]=u;
    }

    int *visited=(int*)calloc(n,sizeof(int));
    int completeCount=0;

    for(int i=0;i<n;i++) {
        if(!visited[i]){
            int nodeCount=0;
            int edgeCount=0;
            dfs(i,n,adj,adjSizes,visited,&nodeCount,&edgeCount);
            if(edgeCount==nodeCount*(nodeCount-1)) completeCount++;
        }
    }

    for(int i=0;i<n;i++)
        free(adj[i]);
    free(adj);
    free(adjSizes);
    free(visited);

    return completeCount;
}
