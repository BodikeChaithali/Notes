#include <stdio.h>

int searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int r = 0, c = cols - 1;
    while(r < rows && c >= 0) {
        if(matrix[r][c] == target)
            return 1;
        else if(matrix[r][c] > target)
            c--;
        else
            r++;
    }
    return 0;
}

int main() {
    int matrixSize = 5;
    int matrixColSize[] = {5,5,5,5,5};

    int row0[] = {1,4,7,11,15};
    int row1[] = {2,5,8,12,19};
    int row2[] = {3,6,9,16,22};
    int row3[] = {10,13,14,17,24};
    int row4[] = {18,21,23,26,30};

    int* matrix[] = {row0, row1, row2, row3, row4};

    int target = 5;

    if(searchMatrix(matrix, matrixSize, matrixColSize, target))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}
