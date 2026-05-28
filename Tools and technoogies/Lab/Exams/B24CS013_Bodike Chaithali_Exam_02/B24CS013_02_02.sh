#!/bin/bash

arr=()
read -p "Enter the array size: " num
echo "The  declared array is: "
for ((i=0;i<num;i++)); do
        read arr[i]
done

gcc  B24CS013_02_02.c -o palindrome
 
echo -n "Palindrome numbers are: "
for ((i=0;i<num;i++));
do
        palindrome=$(./palindrome $"${arr[i]}")
        echo  -n "$palindrome "
done
echo ""
