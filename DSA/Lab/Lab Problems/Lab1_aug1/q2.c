#include<stdio.h>
#include<stdlib.h>

void findMinMax(int *arr,int n,int *min,int *max) {
	*min=*max=*(arr+0);
	for(int i=0;i<n;i++) {
		if(*(arr+i)<*min) *min=*(arr+i);
		if(*(arr+i)>*max) *max=*(arr+i);
	}
}

int main () {
	int n,min,max;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int *arr;
	arr=(int *)malloc(n*sizeof(int));
	printf("Input the array elements:");
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	findMinMax(arr,n,&min,&max);
	printf("Maximum=%d and Minimum=%d\n",max,min);
	free(arr);
	return 0;
}
