#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int find(int *parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]); 
    return parent[x];
}

void unionSets(int *parent, int *rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a != b) {
        if (rank[a] < rank[b]) parent[a] = b;
        else if (rank[a] > rank[b]) parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int minRepairCost(Edge *edges, int n, int m) {
    qsort(edges, m, sizeof(Edge), compare);

    int *parent = malloc((n + 1) * sizeof(int));
    int *rank = calloc((n + 1), sizeof(int));
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int totalCost = 0, edgesUsed = 0;
    for (int i = 0; i < m && edgesUsed < n - 1; i++) {
        int pu = find(parent, edges[i].u);
        int pv = find(parent, edges[i].v);
        if (pu != pv) {
            totalCost += edges[i].w;
            unionSets(parent, rank, pu, pv);
            edgesUsed++;
        }
    }

    free(parent);
    free(rank);
    return totalCost;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);//n no.of cites and m no.of egeds

    Edge *edges = malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    printf("%d\n", minRepairCost(edges, n, m));

    free(edges);
    return 0;
}
