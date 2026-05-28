#include<stdio.h>

void main () {
    int n;printf("Enter the no.of words:");scanf("%d",&n);
    char arr[n][100];
    for(int i=1;i<=n;i++) {
        printf("Enter word %d:",i);scanf("%s",arr[i]);
    }
    printf("Entered words:\n");
    for(int i=1;i<=n;i++) printf("%s\n",arr[i]);
}