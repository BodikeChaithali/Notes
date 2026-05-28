#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ---------------- VALID PATH FUNCTION ---------------- */
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    int* graphColSize = (int*)calloc(n, sizeof(int));

    // Count neighbors
    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        graphColSize[a]++;
        graphColSize[b]++;
    }

    // Allocate adjacency list
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(graphColSize[i] * sizeof(int));
        graphColSize[i] = 0;  // reset to reuse as index counter
    }

    // Build graph
    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        graph[a][graphColSize[a]++] = b;
        graph[b][graphColSize[b]++] = a;
    }

    // BFS
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = source;
    visited[source] = true;

    while (front < rear) {
        int node = queue[front++];

        if (node == destination) {
            for (int i = 0; i < n; i++) free(graph[i]);
            free(graph);
            free(graphColSize);
            free(visited);
            free(queue);
            return true;
        }

        for (int i = 0; i < graphColSize[node]; i++) {
            int next = graph[node][i];
            if (!visited[next]) {
                visited[next] = true;
                queue[rear++] = next;
            }
        }
    }

    for (int i = 0; i < n; i++) free(graph[i]);
    free(graph);
    free(graphColSize);
    free(visited);
    free(queue);

    return false;
}

/* ---------------- MAIN FUNCTION ---------------- */
int main() {
    int n, edgesSize;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edgesSize);

    int** edges = (int**)malloc(edgesSize * sizeof(int*));
    int* edgesColSize = (int*)malloc(edgesSize * sizeof(int));

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edgesSize; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        edgesColSize[i] = 2;
    }

    int source, dest;
    printf("Enter source node: ");
    scanf("%d", &source);
    printf("Enter destination node: ");
    scanf("%d", &dest);

    bool result = validPath(n, edges, edgesSize, edgesColSize, source, dest);

    if (result)
        printf("Path exists between %d and %d\n", source, dest);
    else
        printf("No path exists between %d and %d\n", source, dest);

    for (int i = 0; i < edgesSize; i++)
        free(edges[i]);
    free(edges);
    free(edgesColSize);

    return 0;
}
