#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int** arr, int gridSize, int* gridColSize) {
    int perimeter = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {

            if (arr[i][j] == 1) {
                perimeter += 4;

                if (i > 0 && arr[i - 1][j] == 1)
                    perimeter -= 2;

                if (j > 0 && arr[i][j - 1] == 1)
                    perimeter -= 2;
            }
        }
    }
    return perimeter;
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate dynamic 2D array
    int** grid = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++)
        grid[i] = (int*)malloc(sizeof(int) * cols);

    int colSize[1] = {cols};

    printf("Enter grid values (0 or 1):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = islandPerimeter(grid, rows, colSize);
    printf("Island Perimeter = %d\n", result);

    // Free memory
    for (int i = 0; i < rows; i++)
        free(grid[i]);
    free(grid);

    return 0;
}
