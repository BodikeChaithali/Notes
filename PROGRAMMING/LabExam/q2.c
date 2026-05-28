#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

// ----------- Solution Function (Equivalent to GFG C++ class) -------------
#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

// ----------- Solution Function (Equivalent to GFG C++ class) -------------
int* shortestPath(int V, int E, int edges[][2], int src) {
    int *deg = (int *)calloc(V, sizeof(int));  

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        deg[u]++;
        deg[v]++;  
    }

    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        if (deg[i] > 0)
            adj[i] = (int *)malloc(deg[i] * sizeof(int));
        else
            adj[i] = NULL;
    }

    int *idx = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][idx[u]++] = v;
        adj[v][idx[v]++] = u;  
    }

    free(idx);  
    int *dist = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) dist[i] = -1;  

    int *queue = (int *)malloc(V * sizeof(int));
    int front = 0, back = 0;

    dist[src] = 0;
    queue[back++] = src;

    while (front < back) {
        int u = queue[front++];

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {         
                dist[v] = dist[u] + 1;   
                queue[back++] = v;
            }
        }
    }

    // ----- Free adjacency list memory -----
    for (int i = 0; i < V; i++) {
        if (adj[i] != NULL) free(adj[i]);
    }
    free(adj);
    free(deg);
    free(queue);

    // dist[] will be printed in main, then freed there
    return dist;
}



// -------------------- MAIN for MULTIPLE TESTCASES -----------------------
int main() {
    // read input from input.txt
    freopen("input.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    while (T--) {
        int V, E;
        scanf("%d %d", &V, &E);

        int (*edges)[2] = malloc(E * sizeof *edges);

        for (int i = 0; i < E; i++)
            scanf("%d %d", &edges[i][0], &edges[i][1]);

        int src;
        scanf("%d", &src);

        int *ans = shortestPath(V, E, edges, src);

        for (int i = 0; i < V; i++) {
            printf("%d", ans[i]);
            if (i + 1 < V) printf(" ");
        }
        printf("\n");

        free(ans);
        free(edges);
    }

    return 0;
}