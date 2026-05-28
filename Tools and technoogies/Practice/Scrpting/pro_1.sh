#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <word>"
    exit 1
fi

word=$1

# Count occurrences of the word in all .csv files
count=$(grep -o -w "$word" *.csv | wc -l)

echo "Total occurrences of '$word' in all CSV files: $count"

