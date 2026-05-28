#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b) {
    int temp=*b;
    *b=*a;
    *a=temp;
}
void maxHeapify(int *arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[largest],&arr[i]);
        maxHeapify(arr, n, largest);
    }
}
void buildMaxHeap(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}
int *mergearrays(int *arr1,int n1,int *arr2,int n2) {
    int *arr=malloc(sizeof(int)*(n1+n2));
    if(!arr) return NULL;
    for (int i = 0; i < n1; i++)
        arr[i] = arr1[i];
    for (int i = 0; i < n2; i++)
        arr[n1 + i] = arr2[i];
    buildMaxHeap(arr,n1+n2);
    return arr;
}

int main() {
    int n1,n2;
    printf("Enter the size of two arrays: ");
    scanf("%d%d",&n1,&n2);
    int *arr1=malloc(sizeof(int)*n1),*arr2=malloc(sizeof(int)*n2);
    printf("Enter the values in array one of size %d:\n",n1);
    for(int i=0;i<n1;i++) scanf("%d",&arr1[i]);
    printf("Enter the values in array two of size %d:\n",n2);
    for(int i=0;i<n2;i++) scanf("%d",&arr2[i]);
    int *arr=mergearrays(arr1,n1,arr2,n2);
    printf("merged two binary max heaps into a single max heap\n[");
    for(int i=0;i<n1+n2;i++) printf("%d, ",arr[i]);
    printf("\b\b]\n");
    free(arr1);
    free(arr2);
    free(arr);
    return 0;
}