#include <stdio.h>

int n, graph[50][50], visited[50];

int isCycle(int v, int parent) {
    visited[v] = 1;
    for(int i = 0; i < n; i++) {
        if(graph[v][i]) {
            if(!visited[i]) {
                if(isCycle(i, v)) return 1;
            }
            else if(i != parent) return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    
    for(int i = 0; i < n; i++) visited[i] = 0;

    if(isCycle(0, -1))
        printf("Cycle Found\n");
    else
        printf("No Cycle\n");
}
