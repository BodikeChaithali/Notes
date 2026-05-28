#!/bin/bash

read -p "Enter filename: " file

if [[ -f "$file" ]]; then 
	lines=$(wc -l < "$file")
	words=$(wc -w < "$file")
	chars=$(wc -m < "$file")
	echo "Number of lines: $lines"
	echo "Number of words: $words"
	echo "Number of characters: $chars"
else 
	echo "404: file not found"
fi
