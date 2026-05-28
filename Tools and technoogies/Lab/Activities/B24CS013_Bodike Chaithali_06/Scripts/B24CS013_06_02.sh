#!/bin/bash

if [ $# -ne 1 ]; then
        echo "Usage: $0 word"
        exit 1
fi

word=$1
count=$(grep -iowh "$word" *.csv | wc -l)

if [ $? -ne 0 ]; then
        echo "No .csv files found"
else
        echo "Total occurrences of '$word':$count"
fi

