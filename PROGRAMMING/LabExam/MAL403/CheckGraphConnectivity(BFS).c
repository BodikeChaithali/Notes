#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int graph[n][n], visited[n], i, j;
    for(i = 0; i < n; i++) {
        visited[i] = 0;
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    int q[n], f = 0, r = 0;
    q[r++] = 0;
    visited[0] = 1;

    while(f < r) {
        int u = q[f++];
        for(i = 0; i < n; i++)
            if(graph[u][i] && !visited[i]) {
                visited[i] = 1;
                q[r++] = i;
            }
    }

    for(i = 0; i < n; i++)
        if(!visited[i]) {
            printf("Not Connected\n");
            return 0;
        }
    
    printf("Connected Graph\n");
}
