#!/bin/bash
read -p "Enter the number: " n
if [ $n -le 1 ]; then
        echo "Not a prime"
        exit
fi      

is_prime=1
for((i=2;i<=n/2;i++)); do 
        if ((n%i==0)); then
                is_prime=0
                break
        fi      
done    
if [ $is_prime -eq 1 ]; then
        echo "Prime Number"
else    
        echo "Not a Prime number" 
fi
