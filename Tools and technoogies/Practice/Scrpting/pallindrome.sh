#!/bin/bash

palindrome () {
	num=$1
	m=$num
	rev=0
	while [[ $m != 0 ]]; do
		rev=$(($((rev*10))+$((m%10))))
		m=$((m/10))
	done
	if [[ $num == $rev ]]; then
		echo "Pallindrome"
	else
		echo "Not a pallindrome"
	fi
}

main () {
	read -p "Enter any number: " n
	palindrome "$n"
}

main 
