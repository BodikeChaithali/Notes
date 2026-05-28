#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]) {
if(argc<2) {
printf("Enter input!");
return 0;
}
int n=atoi(argv[1]);
if(n >=0 && n<=9) return n;
int m=n;
int rev=0;
while(m!=0) {
rev=rev*10+m%10;
m/=10;
}
if(rev==n) printf("%d",n);
else return 0;
}
