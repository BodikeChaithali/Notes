#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Enter only one value"
	exit 1
fi
num=$1
gcc primes.c -o primes

for ((i=1;i<num;i++)); do
	output=$(./primes $i)
	if [ ! -z "$output" ]; then
		echo -n "$output "
	fi
done
echo ""
