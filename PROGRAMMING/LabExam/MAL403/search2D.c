#include <stdio.h>

int searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int st = 0;
    int end = rows * cols - 1;

    while(st <= end) {
        int mid = st + (end - st) / 2;
        int r = mid / cols;
        int c = mid % cols;
        int val = matrix[r][c];

        if(val == target) return 1;
        else if(val < target) st = mid + 1;
        else end = mid - 1;
    }
    return 0;
}

int main() {
    int matrixSize = 3;
    int matrixColSize[] = {4,4,4};
    
    int row0[] = {1, 3, 5, 7};
    int row1[] = {10, 11, 16, 20};
    int row2[] = {23, 30, 34, 60};

    int* matrix[] = {row0, row1, row2};

    int target = 3;
    
    if(searchMatrix(matrix, matrixSize, matrixColSize, target))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}
