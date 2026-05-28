#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Enter an input!"
	exit
fi
word_count=$(grep -iowh "$1" *.csv | wc -l )
echo "Word count: $word_count"
