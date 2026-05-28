#include <stdio.h>

int main() {
    int n, i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int visited[n];

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        visited[i] = 0;
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    int queue[n], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for(i = 0; i < n; i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    return 0;
}
