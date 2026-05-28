#include<stdio.h>

int main () {
    int arr[]={1,2,3,4,5};
    printf("The revresed array is:\n");
 for(int i=0;i<5/2;i++){
    int temp=arr[i];
         arr[i]=arr[5-i-1];
         arr[5-i-1]=temp;
        printf("arr[%d]=%d\n",i,arr[i]);
    }
    for(int i=5/2;i<5;i++){
        printf("arr[%d]=%d\n",5/2+i-1,arr[i]);
        }
        return 0;
}
