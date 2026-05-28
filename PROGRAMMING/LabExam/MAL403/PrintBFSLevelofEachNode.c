#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int graph[n][n], level[n], i, j;
    for(i=0;i<n;i++){
        level[i]=-1;
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }

    int q[n],f=0,r=0;
    int start=0;
    q[r++]=start; level[start]=0;

    printf("Levels:\n");
    while(f<r){
        int u=q[f++];
        printf("Node %d -> Level %d\n",u, level[u]);
        for(i=0;i<n;i++){
            if(graph[u][i] && level[i]==-1){
                level[i]=level[u]+1;
                q[r++]=i;
            }
        }
    }
}
