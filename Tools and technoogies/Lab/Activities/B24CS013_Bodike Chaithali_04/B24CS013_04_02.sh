#!/bin/bash

read -p "Enter the number: " n
if (( $n>100 || $n<0 )); then
	echo "Invalid Input!"
	exit
fi

if (( $n>=80 && $n<=100 )); then
	echo "Grade = A"
elif (( $n<=79 && $n>=60 )); then
	echo "Grade = B"
elif (( $n>=40 && $n<=59 )); then 
	echo "Grade = C"
else
	echo "Fail!"
fi
