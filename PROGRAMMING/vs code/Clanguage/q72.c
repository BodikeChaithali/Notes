#include<stdio.h>

void main() {
    int n;
    printf("Enter size of the array:");scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        if(arr[i]=='\0') continue;
        int c=1;
        for(int j=i+1;j<n;j++) {
            if(arr[i]==arr[j])
            {
            c++;
            arr[j]='\0';
            }
        }
        printf("%d found %d times\n",arr[i],c);
    }
}