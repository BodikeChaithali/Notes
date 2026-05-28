#include <stdio.h>
#include <stdlib.h>

// ---- WRITE YOUR LOGIC HERE ----
// return dynamically allocated array of medians
void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
double median(int *arr,int n) {
    if(n==0) return (double)arr[n];
    if(n%2==0) return (double)arr[n/2];
    else return (double)(arr[n/2]+arr[n/2+1])/2;
}
double* solveTestcase(int n, int a[], int *outSize) {
    *outSize=n;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i]<a[j]) swap(&a[i],&a[j]);
        }
    }
    double *ans=(double *)calloc(n,sizeof(double));
    for(int i=0;i<n;i++) {
            ans[i]=median(a,i);
    }
    return ans;
}
// --------------------------------

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int *a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int outSize;
        double *medians = solveTestcase(n, a, &outSize);

        for (int i = 0; i < outSize; i++)
            printf("%.1f ", medians[i]);
        printf("\n");

        free(a);
        free(medians);
    }

    return 0;
}