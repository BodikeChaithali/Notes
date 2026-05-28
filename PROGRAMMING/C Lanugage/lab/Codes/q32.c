#include<stdio.h>

void main () {
    int n,c=0;
    printf("Input the number of elements to be stored in the array:");scanf("%d",&n);
    int arr[n];
    printf("Input %d elements in the array :\n",n);
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        int duplicate=0;
        for(int j=0;j<i;j++) {
            if(arr[i]==arr[j]) {
                duplicate=1;
                break;
            }   
        }
        if(duplicate==0) {
            int f=0;
            for(int j=i+1;j<n;j++) {
                if(arr[i]==arr[j]) f++;
            }
            if (f>0) c++;
        }
    }
    if(c==0) puts("No duplicate elements");
    else printf("Total no.of duplicate elements found in array:%d\n",c);
}