#include <stdio.h>
#include <stdlib.h>

int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n = gridSize * gridSize;
    int* freq = (int*)calloc(n + 1, sizeof(int));
    *returnSize = 2;
    int* ans = (int*)malloc(sizeof(int) * 2);

    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridColSize[i]; j++) {
            freq[grid[i][j]]++;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(freq[i] == 2) ans[0] = i;
        if(freq[i] == 0) ans[1] = i;
    }

    free(freq);
    return ans;
}

int main() {
    int gridSize = 2;
    int gridColSize[] = {2, 2};

    int row0[] = {1, 3};
    int row1[] = {2, 2};
    int* grid[] = {row0, row1};

    int returnSize;
    int* result = findMissingAndRepeatedValues(grid, gridSize, gridColSize, &returnSize);

    printf("[%d, %d]\n", result[0], result[1]);

    free(result);
    return 0;
}
