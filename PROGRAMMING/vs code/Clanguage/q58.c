#include<stdio.h>

void main () {
    int n;
    printf("Enter n value:");scanf("%d",&n);
    int arr[n],t;
    printf("Input Arrays:\n");
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    int deletedelement;
    printf("Enter element which have to deleted:");scanf("%d",&deletedelement);
    int i,j,f=0;
    for(i=0;i<n;i++) {
        if(arr[i]==deletedelement){
            for(n--,f=0,j=i;j<n;j++) {arr[j]=arr[j+1];f++;}
            i--;//if i=0;arr[0]=arr[1] after if exicuted so i--=0(i=1)
        }
    }
    if(f==0) {printf("%d element not found!\n",deletedelement);}
    else 
    {
        printf("New array!!\n");
        for(int j=0;j<n-1;j++) {
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}