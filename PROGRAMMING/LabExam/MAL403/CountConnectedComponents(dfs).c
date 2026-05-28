#include <stdio.h>

int n, graph[50][50], visited[50];

void dfs(int v) {
    visited[v] = 1;
    for(int i = 0; i < n; i++)
        if(graph[v][i] && !visited[i])
            dfs(i);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            count++;
            dfs(i);
        }
    }
    printf("Connected Components = %d\n", count);
}
