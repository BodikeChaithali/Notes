#include<stdlib.h>
#include<stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partitionFirst(int arr[], int low, int high) {
    int pi=arr[low];
    int i=low+1;
    int j=high;
    while(1) {
        while(i<=high &&  arr[i]<=pi) i++;
        while(arr[j]>pi) j--;
        if(i>=j) break;
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quickSortFirst(int arr[], int low, int high) {
    if(low<high) {
        int p=partitionFirst(arr,low,high);
        quickSortFirst(arr,low,p-1);
        quickSortFirst(arr,p+1,high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);

    quickSortFirst(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}