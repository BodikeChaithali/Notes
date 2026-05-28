#!/bin/bash

files=("a.txt" "loops.sh" "filename.sh")

for i in "${files[@]}" 
do
	if [ -f "$i" ]; then
		echo "$i exists"
	else
		echo "$i does not exists"
	fi
done
