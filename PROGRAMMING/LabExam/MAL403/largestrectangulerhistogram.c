#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc(sizeof(int) * (heightsSize + 1));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        int currHeight = (i == heightsSize) ? 0 : heights[i];
        while (top >= 0 && currHeight < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea) maxArea = area;
        }
        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int size = sizeof(heights) / sizeof(heights[0]);

    int result = largestRectangleArea(heights, size);
    printf("%d\n", result);

    return 0;
}
