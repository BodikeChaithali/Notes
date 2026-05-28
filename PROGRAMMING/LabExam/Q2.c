#include <stdio.h>

int main() {
    int n, i, j, src;
    scanf("%d", &n);

    int graph[n][n], dist[n];
    for(i = 0; i < n; i++) {
        dist[i] = -1;
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    scanf("%d", &src);

    int q[n], f = 0, r = 0;
    q[r++] = src;
    dist[src] = 0;

    while(f < r) {
        int node = q[f++];
        for(i = 0; i < n; i++) {
            if(graph[node][i] && dist[i] == -1) {
                dist[i] = dist[node] + 1;
                q[r++] = i;
            }
        }
    }

    for(i = 0; i < n; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}
