#include <stdio.h>

void findPeaks(int a[], int n) {
    for(int i=0;i<n;i++){
        if((i==0 || a[i] > a[i-1]) &&
           (i==n-1 || a[i] > a[i+1]))
            printf("%d ", i);
    }
}

int main() {
    int a[] = {23,21,30,27,44,35,48};
    int n = 7;
    
    printf("Peak indices: ");
    findPeaks(a,n);
    return 0;
}
