#include <stdio.h>

int n, adj[50][50], visited[50];

void dfs(int u){
    visited[u]=1;
    printf("%d ",u);
    for(int v=0;v<n;v++)
        if(adj[u][v] && !visited[v])
            dfs(v);
}

int main(){
    int e;
    scanf("%d %d",&n,&e);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;

    while(e--){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }

    int start;
    scanf("%d",&start);

    dfs(start);
}
