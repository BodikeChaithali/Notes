#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;
    *returnSize = 0;

    int *results = malloc(sizeof(int) * (matrixSize * matrixColSize[0]));

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            results[(*returnSize)++] = matrix[top][i];
        top++;

        for (int i = top; i <= bottom; i++)
            results[(*returnSize)++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                results[(*returnSize)++] = matrix[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                results[(*returnSize)++] = matrix[i][left];
            left++;
        }
    }
    return results;
}

int main() {
    int matrixSize = 3;
    int matrixColSize[] = {3, 3, 3};

    int** matrix = malloc(matrixSize * sizeof(int*));
    matrix[0] = (int[]) {1, 2, 3};
    matrix[1] = (int[]) {4, 5, 6};
    matrix[2] = (int[]) {7, 8, 9};

    int returnSize;
    int* result = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);

    printf("Spiral Order: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    free(result);
    free(matrix);

    return 0;
}
