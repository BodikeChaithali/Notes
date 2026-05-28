#include <stdio.h>

int n, graph[100][100], visited[100];

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++) {
        if(graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);
    return 0;
}
