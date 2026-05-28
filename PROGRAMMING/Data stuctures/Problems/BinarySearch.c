#include<stdio.h>

int fingTarget(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return left; // Target not found, return insertion point
}
int main() {
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the target value: ");
    scanf("%d", &target);
    
    int result = fingTarget(arr, n, target);
    printf("The target should be at index: %d\n", result);
    
    return 0;
}