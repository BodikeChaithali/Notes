#include<stdio.h>

int isPrime(int n){
    if(n <= 1){
        return 1;
    }
    else if(n == 2){
        return 0;
    }
    else if(n % 2 == 0){
        return 1;
    }
    for(int i = 3;i * i <= n;i = i + 2){
        if(n % i == 0){
            return 1;
        }
        return 0;
    }
}
    int sumoftwoPrimes(int n){
        if(n <= 2){
            return 1;
        }
        for(int i = 2;i < n;i++){
            if(isPrime(i)){
                int complement = n - i;
                if(complement != i && isPrime(complement)){
                    return 0;
                }
}
        }
        return 1;
    } 


int main(){
    int n;
    printf("Enter a positive integer:");
    scanf("%d", &n);
    if(sumoftwoPrimes(n)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return 0;
}
