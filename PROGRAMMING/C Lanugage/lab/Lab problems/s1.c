#include<stdio.h>
int main(){
int a,c=0;
printf("Enter a number:");
scanf("%d",&a);
for(int k=1 ; k<=a; k++){
for(int i=0; i<=a; i++){
    for(int j=i; j<=a; j++){
        if(k==i*i+j*j){
            c=c+1;
            i=a;
        }
    }
}
}
printf(" Number of integersb<= 10 %d\n.expression as sum of squares %d"0,a,c);
return 0;
}
