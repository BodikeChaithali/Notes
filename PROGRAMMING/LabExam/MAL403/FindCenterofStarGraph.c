#include <stdio.h>
#include <stdlib.h>

int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int a = edges[0][0];
    int b = edges[0][1];

    if (edges[1][0] == a || edges[1][1] == a)
        return a;
    return b;
}

int main() {
    int edgesSize;

    printf("Enter number of edges: ");
    scanf("%d", &edgesSize);

    // star graph → each edge has 2 nodes
    int* edgesColSize = (int*)malloc(sizeof(int) * edgesSize);
    int** edges = (int**)malloc(sizeof(int*) * edgesSize);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edgesSize; i++) {
        edges[i] = (int*)malloc(sizeof(int) * 2);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        edgesColSize[i] = 2;
    }

    int center = findCenter(edges, edgesSize, edgesColSize);
    printf("Center of star graph = %d\n", center);

    // free memory
    for (int i = 0; i < edgesSize; i++)
        free(edges[i]);
    free(edges);
    free(edgesColSize);

    return 0;
}
