#!/bin/bash

greatest() {
	arr=("$@")
	max=${arr[0]}
	for i in "${arr[@]}"; do
		if (( i > max )); then
			max=$i
		fi
	done
	echo $max
}

main() {
	read -p "Enter the number of elements: " n
	arr=() 
	echo "Enter $n elements:"
	for ((i=0;i<n;i++)); do
		read num
		arr+=($num)
	done
	max=$(greatest "${arr[@]}")
	echo "Maximum element is : $max"
}

main
