#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1=m-l+1;
    int n2=r-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++) left[i]=arr[l+i];
    for(int j=0;j<n2;j++) right[j]=arr[m+j+1];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(left[i]<=right[j]) {
            arr[k]=left[i];
            i++;
        }
        else {
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[k]=right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
