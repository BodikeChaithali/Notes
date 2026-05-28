#include <stdio.h>

int main(){
    int n, e;
    scanf("%d %d", &n, &e);

    int adj[n][n], visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        for(int j=0;j<n;j++) adj[i][j]=0;
    }

    while(e--){
        int u, v;
        scanf("%d %d",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }

    int start;
    scanf("%d",&start);

    int q[n], f=0,r=0;
    q[r++]=start; visited[start]=1;

    while(f<r){
        int u=q[f++];
        printf("%d ",u);
        for(int v=0;v<n;v++){
            if(adj[u][v] && !visited[v]){
                visited[v]=1;
                q[r++]=v;
            }
        }
    }
}
