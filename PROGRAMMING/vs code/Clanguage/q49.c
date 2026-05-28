#include<stdio.h>

void main () {
    int start,end,c=0;
    printf("Enter start and end number:");scanf("%d %d",&start,&end);
    if(start>end) {start=start^end;end=start^end;start=start^end;}
    if(start==1) start=start+1;
    printf("Prime number are: ");
    for(int i=start;i<=end;i++) {
        int j;
        for(j=2;j<i;j++) {
            if(i%j==0) goto b;
        }
        printf("%d ",i);c++;b:
    }
    printf("\nNo.of prime number in between %d and %d = %d\n",start,end,c);
}