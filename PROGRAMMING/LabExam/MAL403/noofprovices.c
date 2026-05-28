#include <stdio.h>
#include <stdlib.h>

void dfs(int **isConnected, int n, int *visited, int i) {
    visited[i] = 1;

    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, visited, i);
            provinces++;
        }
    }
    return provinces;
}

/* MAIN FUNCTION */
int main() {
    int n;

    printf("Enter number of cities (n): ");
    scanf("%d", &n);

    // Allocate matrix
    int **matrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(sizeof(int) * n);

    int colSize[1] = {n};

    printf("Enter the %d x %d adjacency matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = findCircleNum(matrix, n, colSize);
    printf("Number of Provinces = %d\n", result);

    // Free memory
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
