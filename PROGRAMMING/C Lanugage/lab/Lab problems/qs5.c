#include<stdio.h>
int sumofdigits(int n)
{
       int sum = 0;
       while(n != 0) {
           sum = sum + n % 10;
           n=n/10;
           
       }
    return sum;
    
}
int isharshad(int n) {
    
    int sum = sumofdigits(n);
    return (n % sum == 0);
}

int main()
{
    int n;
    printf("enter a number");
    scanf("%d",&n);
    
    if(isharshad(n))
    { 
	    printf("%d is the harshad number (%d/%d =%d)\n",n,n,sumofdigits(n),n/sumofdigits(n));
    }
    
    else 
    {
	    printf("%d is not a harshad number.\n",n);
    }
    
    return 0; 
    
}
